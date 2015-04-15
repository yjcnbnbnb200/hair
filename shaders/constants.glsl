/**
 * Constants that can be included in other shaders using:
 *
 * #include "constants.glsl"
 */

// Hair material properties
const float HAIR_SHININESS = 40.0;
const float HAIR_SPEC_INTENSITY = 0.5;
const float HAIR_DIFFUSE_INTENSITY = 1.0;

// Mesh material properties
const vec3 MESH_COLOR = vec3(221.0, 211.0, 238.0) / 255.0;
const float MESH_DIFFUSE_INTENSITY = 0.3;
const float MESH_AMBIENT_INTENSITY = 0.2;

// Fill light properties
const vec4 FILL_LIGHT_POS = vec4(-2.0, -1.0, 1.0, 1.0);
const float FILL_LIGHT_INTENSITY = 0.4;