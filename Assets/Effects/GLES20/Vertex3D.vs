

const char * Vertex3DVS = STRINGIFY(

attribute vec3	a_position;
attribute vec2	a_texCoord;
attribute vec3 a_normal;
                                    
uniform	mat4	PMVMatrix;
varying vec2    v_texCoord;
                                    
varying float diffuseFactor;
                                    
void main(void)
{

    v_texCoord = a_texCoord;
    gl_Position = PMVMatrix * vec4(a_position.x, a_position.y, a_position.z, 1.0);
    
    vec4 newNormal = PMVMatrix * vec4(a_normal.xyz, 1.0);
    vec3 light1 = normalize(vec3(1.0, 1.0, 1.0));
    vec3 light2 = normalize(vec3(-10.0, -10.0, -10.0));
    diffuseFactor = 0.6 * max(0.0, dot(newNormal.xyz, light1)) + 0.3*max(0.0, dot(newNormal.xyz, light2));

}

);