
const char * Vertex3DFS = STRINGIFY(

precision mediump float;
uniform sampler2D sampler2d;
                                
varying vec2	v_texCoord;
varying highp float diffuseFactor;
                                    
void main (void)
{
    
    float df = diffuseFactor;
    
    lowp vec4 white = vec4(1.0, 1.0, 0.0, 1.0);
    
    gl_FragColor = texture2D(sampler2d, v_texCoord) * vec4((white * df).rgb, 1.0);
    
    // For Web GL... Some how the textures on banana are not working... Need to check that out...
    //gl_FragColor = vec4((white * df).rgb * 0.7, 1.0);
}

);