

const char * VertexBoilVS = STRINGIFY(

attribute vec3	a_position;

attribute vec3 a_normal;
uniform float u_angle;
                                      
uniform	mat4	PMVMatrix;

                                    
varying float diffuseFactor;
                                    
void main(void)
{

    
    float DELTA = 7.0;
    vec3 newVec = a_position + vec3(sin(2.0*a_position.y+u_angle)/DELTA, sin(2.0*a_position.x+u_angle)/DELTA, 0.0);
    
    gl_Position = PMVMatrix * vec4(newVec.x, newVec.y, newVec.z, 1.0);
    
    vec4 newNormal = PMVMatrix * vec4(a_normal.xyz, 1.0);
    
    vec3 light1 = normalize(vec3(1.0, 1.0, 1.0));
    vec3 light2 = normalize(vec3(-10.0, -10.0, -10.0));
    diffuseFactor = 0.1 * max(0.0, dot(newNormal.xyz, light1)) + 0.05*max(0.0, dot(newNormal.xyz, light2));

}

);