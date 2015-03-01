
const char * VertexBoilFS = STRINGIFY(

precision mediump float;

varying highp float diffuseFactor;
                                    
void main (void)
{
    
    lowp vec4 white = vec4(1.0, 1.0, 1.0, 1.0);
    
    gl_FragColor = vec4((white * diffuseFactor).rgb, 1.0);
    
}

);