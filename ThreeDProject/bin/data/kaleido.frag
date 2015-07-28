#version 120
#extension GL_ARB_texture_rectangle:enable

#define PI (3.14159265)
#define TWO_PI (2*PI)

uniform int ksectors = 10;
uniform float kangleRad = 0.0;
uniform vec2 kcenter = vec2(1280.0, 720.0) / 2.0;
uniform vec2 screenCenter = vec2(1280.0, 720.0) / 2.0;
uniform sampler2D tex;


void main(){
    vec2 texCoord = gl_TexCoord[0].xy;
    vec2 v = texCoord - screenCenter;
    float r = length(v);
    float a = atan(v.y, v.x);
    a = mod(a, TWO_PI);
    float rad = a + (r);
    vec2 u = vec2(cos(rad), sin(rad)) * r;
    u += kcenter;
    gl_FragColor = texture2D(tex, u);
    
}