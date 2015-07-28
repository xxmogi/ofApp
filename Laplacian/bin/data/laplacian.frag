#version 120

uniform sampler2DRect tex0;
uniform float val;

void main() {
    vec2 texCoord = gl_TexCoord[0].xy;
    vec4 color = 20 *  texture2DRect(tex0, texCoord);
    
    color -= texture2DRect(tex0, texCoord + vec2(-2.0,-2.0));
    color -= 3 * texture2DRect(tex0, texCoord + vec2(-2.0,-1.0));
    color -= 4 * texture2DRect(tex0, texCoord + vec2(-2.0, 0.0));
    color -= 3 * texture2DRect(tex0, texCoord + vec2(-2.0, 1.0));
    color -= texture2DRect(tex0, texCoord + vec2(-2.0, 2.0));
    
    color -= 3 * texture2DRect(tex0, texCoord + vec2(-1.0,-2.0));
    color -= 0 * texture2DRect(tex0, texCoord + vec2(-1.0,-1.0));
    color += 6 * texture2DRect(tex0, texCoord + vec2(-1.0, 0.0));
    color -= 0 * texture2DRect(tex0, texCoord + vec2(-1.0, 1.0));
    color -= 3 * texture2DRect(tex0, texCoord + vec2(-1.0, 2.0));
    
    color -= 4 * texture2DRect(tex0, texCoord + vec2(0.0,-2.0));
    color += 6 * texture2DRect(tex0, texCoord + vec2(0.0,-1.0));
    color += 6 * texture2DRect(tex0, texCoord + vec2(0.0, 1.0));
    color -= 4 * texture2DRect(tex0, texCoord + vec2(0.0, 2.0));
    
    color -= 3 * texture2DRect(tex0, texCoord + vec2(1.0,-2.0));
    color -= 0 * texture2DRect(tex0, texCoord + vec2(1.0,-1.0));
    color += 6 * texture2DRect(tex0, texCoord + vec2(1.0, 0.0));
    color -= 0 * texture2DRect(tex0, texCoord + vec2(1.0, 1.0));
    color -= 3 * texture2DRect(tex0, texCoord + vec2(1.0, 2.0));
    
    color -= texture2DRect(tex0, texCoord + vec2(2.0,-2.0));
    color -= 3 * texture2DRect(tex0, texCoord + vec2(2.0,-1.0));
    color -= 4 * texture2DRect(tex0, texCoord + vec2(2.0,0.0));
    color -= 3 * texture2DRect(tex0, texCoord + vec2(2.0,1.0));
    color -= texture2DRect(tex0, texCoord + vec2(2.0,2.0));
    
    gl_FragColor = vec4(color.r, 0,0 ,1 );
}