
const char * ToonFS = STRINGIFY(

precision mediump float;
uniform sampler2D sampler2d;
                                
varying vec2	v_texCoord;
varying highp float diffuseFactor;
                                    
void main (void)
{
    
    float df = diffuseFactor;
    
    if (df < 0.1) df = 0.0;
    else if (df < 0.4) df = 0.4;
    else if (df < 0.7) df = 0.7;
    else df = 1.0;
    
    lowp vec4 blue = vec4(0.7, 0.7, 1.0, 1.0);
    
    gl_FragColor = vec4((blue * df).rgb, 1.0);
}

);