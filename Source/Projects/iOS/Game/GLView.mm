//
//  GLView.m
//  WordGame
//
//  Created by Fakhir Shaheen on 24/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//


#import "GLView.h"
#import <System/App.h>
//#import "../../../FEngine/StateManager/StateManager.h"
#import <ResourceCache/IOManagerDefault.h>
#import <Renderer/GLES20/RendererGLES20.h>
#import <System/SystemConfig.h>

//#import "../../../GameLogic/Screens/GamePlay.h"
//#import "../../../GameLogic/Screens/SplashScreen1.h"
//#import "../../../GameLogic/Screens/TestLetterBox.h"
//#import "../../../GameLogic/Screens/TestTexture.h"
//#import "../../../GameLogic/Screens/TBD_TestScreens/LoadScreen.h"


using namespace Fakhir;
App * gApp;

@implementation GLView

+ (Class) layerClass
{
    return [CAEAGLLayer class];
}

- (id) initWithFrame: (CGRect) frame
{
    
    if (self = [super initWithFrame:frame])
    {
        CAEAGLLayer * eaglLayer = (CAEAGLLayer *) super.layer;
        eaglLayer.opaque = true;
        _glContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
        
        if (!_glContext || ![EAGLContext setCurrentContext:_glContext]) {
            //[self release];
            return nil;
        }
     
        Fakhir::SystemConfig sysConfig;
        
        
        // Initialization code...
        GLuint frameBuffer, renderBuffer, depthBuffer;
        
        glGenFramebuffers(1, &frameBuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
        
        glGenRenderbuffers(1, &renderBuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, renderBuffer);
        
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, renderBuffer);
        
        [_glContext renderbufferStorage:GL_RENDERBUFFER fromDrawable:eaglLayer];
        
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &sysConfig.frameBufferWidth);
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &sysConfig.frameBufferHeight);
        
        glGenRenderbuffers(1, &depthBuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, depthBuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, sysConfig.frameBufferWidth, sysConfig.frameBufferHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthBuffer);
        
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            NSLog(@"Failed to make complete framebuffer object %x", glCheckFramebufferStatus(GL_FRAMEBUFFER));
        
        glEnable(GL_DEPTH_TEST);
        
        glBindRenderbuffer(GL_RENDERBUFFER, renderBuffer);
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        
        // WARNING ..... WARNING ..... WARNING ..... WARNING ..... WARNING
        // Due to some Bug, for now the resolution MUST be 960x640.
        // Please run on iPhone 4 or 4s simulator or device only.
        if(sysConfig.frameBufferWidth != 960 || sysConfig.frameBufferHeight != 640)
        {
            NSAssert(false, @"\n========================\n\nResolution MUST be 960x640. Please run on iPhoe 4 or 4s simulator.\n\n========================\n");
            return nil;
        }
        
        
        //IOManager * ioMgr = new IOManagerDefault();
        
        // Create game engine module
        gApp = new App();
        
        sysConfig.renderer = new RendererGLES20();
        
        // Get bundle root directory.
        NSString * bundlePath = [[NSBundle mainBundle] resourcePath];
        const char *cpath = [bundlePath fileSystemRepresentation];
        sysConfig.assetPath = std::string(cpath) + "/";
        //gApp->SetBundlePath(newPath.c_str());
        
        sysConfig.ioManager = new Fakhir::IOManagerDefault();
        vector<char> buffer;
        string sysConfXMLPath = sysConfig.assetPath + "Config/SystemConfig.xml";
        sysConfig.ioManager->GetAssetStream(sysConfXMLPath, buffer);
        sysConfig.LoadConfig(buffer);
        
        
        CGRect screenBounds = [[UIScreen mainScreen] bounds];
        sysConfig.deviceContentScaleFactor = [[UIScreen mainScreen] scale];
        
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &sysConfig.frameBufferWidth);
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &sysConfig.frameBufferHeight);
        sysConfig.logicalWidth    =   screenBounds.size.width;
        sysConfig.logicalHeight   =   screenBounds.size.height;
        
        
        // Initialize Game engine application module
        if (!gApp->Init(&sysConfig))
        {
            // Error initialising game engine
            return nil;
        }
        
        // Load splash screen as the initial screen
        //StatePtr statePtr = boost::make_shared<SplashScreen1>();
        //StatePtr statePtr = boost::make_shared<GamePlay>();
        //StatePtr statePtr = boost::make_shared<TestLetterBox>();
        //StatePtr statePtr = boost::make_shared<TestTexture>();
        //StatePtr statePtr = boost::make_shared<LoadScreen>();
        //StateManager::Get()->ChangeState(statePtr);

        
        _timeStamp = CACurrentMediaTime();
        
        CADisplayLink * displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(drawView:)];
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    
    }
    
    return self;
}

- (void) drawView :(CADisplayLink*) displayLink
{
    float dt = 0.0f;
    
    if (displayLink != nil) {
        dt = displayLink.timestamp - _timeStamp;
        _timeStamp = displayLink.timestamp;
    }
    
    gApp->Tick(dt);
    
    [_glContext presentRenderbuffer:GL_RENDERBUFFER];
}

- (void) dealloc
{
    if ([EAGLContext currentContext] == _glContext)
    {
        [EAGLContext setCurrentContext:nil];
    }
    //[_glContext release];
    //[super dealloc];
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch * touch = [touches anyObject];
    CGPoint logicalLocation = [touch locationInView:self];
    
    float frameBufferWidth = gApp->GetFrameBufferWidth();
    float frameBufferHeight = gApp->GetFrameBufferHeight();
    float logicalWidth = gApp->GetLogicalWidth();
    float logicalHeight = gApp->GetLogicalHeight();
    
    CGPoint actualLocation = CGPointMake(logicalLocation.x / logicalWidth * frameBufferWidth,
                                         (logicalHeight - logicalLocation.y) / logicalHeight * frameBufferHeight);
    
    gApp->TouchDown(actualLocation.x, actualLocation.y);
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    
    UITouch * touch = [touches anyObject];
    CGPoint logicalLocation = [touch locationInView:self];
    
    float frameBufferWidth = gApp->GetFrameBufferWidth();
    float frameBufferHeight = gApp->GetFrameBufferHeight();
    float logicalWidth = gApp->GetLogicalWidth();
    float logicalHeight = gApp->GetLogicalHeight();
    
    CGPoint actualLocation = CGPointMake(logicalLocation.x / logicalWidth * frameBufferWidth,
                                         (logicalHeight - logicalLocation.y) / logicalHeight * frameBufferHeight);
    
    gApp->TouchMoved(actualLocation.x, actualLocation.y);

     
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    
    UITouch * touch = [touches anyObject];
    CGPoint logicalLocation = [touch locationInView:self];
    
    float frameBufferWidth = gApp->GetFrameBufferWidth();
    float frameBufferHeight = gApp->GetFrameBufferHeight();
    float logicalWidth = gApp->GetLogicalWidth();
    float logicalHeight = gApp->GetLogicalHeight();
    
    CGPoint actualLocation = CGPointMake(logicalLocation.x / logicalWidth * frameBufferWidth,
                                         (logicalHeight - logicalLocation.y) / logicalHeight * frameBufferHeight);
    
    gApp->TouchUp(actualLocation.x, actualLocation.y);
    
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    // Insert touch cancel code here...
}

@end