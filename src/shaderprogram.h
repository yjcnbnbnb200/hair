#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "hairCommon.h"
#include <map>
#include <string>

#define MAX_HAIR_VERTICES 64

struct Uniforms {
    glm::mat4 model, view, projection;

    // Number of vertices in the current guide hair.
    int numHairVertices;

    // Vertex position data for the current guide hair.
    glm::vec3 vertexData[MAX_HAIR_VERTICES];

    // Number of duplicates rendered with single-hair interpolation for each guide hair.
    int numGroupHairs;

    // Number of vertices rendered with a spline.
    int numSplineVertices;

    // Defines the width that a hair group is spread across.
    float hairGroupSpread;

    // The radius of a single hair.
    float hairRadius;

    // Exponent used for tapering the hair. The higher the exponent, the closer to the end the
    // tapering occurs.
    float taperExponent;

    // Controls mount of noise in interpolated hairs. Should probably be in range [0, 0.1]
    float noiseAmplitude;

    // Basis vectors for the plane orthogonal to the hair's normal vector.
    glm::vec3 triangleFace[2];

    // Hair color.
    glm::vec3 color;
};

class ShaderProgram
{
public:
    ShaderProgram();

    void create();

    void bind();

    void unbind();

    // Sends all global uniforms to the shader program.
    void setGlobalUniforms();

    // Sends all hair object-specific uniforms to the shader program.
    void setPerHairObjectUniforms();

    // Sends all guide hair-specific uniforms to the shader program.
    void setPerGuideHairUniforms();

    Uniforms uniforms;

private:
    GLuint m_id;
    std::map<std::string, int> m_uniformLocs;
};

#endif // SHADERPROGRAM_H
