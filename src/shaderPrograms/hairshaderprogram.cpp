#include "hairshaderprogram.h"

#include "resourceloader.h"

GLuint HairShaderProgram::createShaderProgram()
{
    return ResourceLoader::createFullShaderProgram(
                ":/shaders/hair.vert", ":/shaders/hair.frag", ":/shaders/hair.geom",
                ":/shaders/hair.tcs", ":/shaders/hair.tes");
}

std::vector<GLchar const *> HairShaderProgram::getUniformNames()
{
    std::vector<GLchar const *> uniformNames {
        "model",
        "view",
        "projection",
        "numPatchHairs",
        "numHairSegments",
        "numSplineVertices",
        "vertexData",
        "hairGroupSpread",
        "hairRadius",
        "taperExponent",
        "noiseAmplitude",
        "triangleFace",
        "color",
        "lightPosition",
        "eyeToLight",
        "shadowMap",
        "noiseTexture",
    };
    return uniformNames;
}

void HairShaderProgram::setGlobalUniforms()
{
    setUniformMatrix4f("view", uniforms.view);
    setUniformMatrix4f("projection", uniforms.projection);
    setUniformMatrix4f("eyeToLight", uniforms.eyeToLight);
    setUniform3f("lightPosition", uniforms.lightPosition);
    setUniform1i("shadowMap", uniforms.shadowMap);
    setUniform1i("noiseTexture", uniforms.noiseTexture);
}

void HairShaderProgram::setPerObjectUniforms()
{
    setUniformMatrix4f("model", uniforms.model);
    setUniform1i("numPatchHairs", uniforms.numGroupHairs);
    setUniform1i("numSplineVertices", uniforms.numSplineVertices);
    setUniform1f("hairGroupSpread", uniforms.hairGroupSpread);
    setUniform1f("hairRadius", uniforms.hairRadius);
    setUniform1f("taperExponent", uniforms.taperExponent);
    setUniform1f("noiseAmplitude", uniforms.noiseAmplitude);
    setUniform3f("color", uniforms.color);
}

void HairShaderProgram::setPerDrawUniforms()
{
    setUniform1i("numHairSegments", uniforms.numHairVertices-1);
    setUniform3fv("vertexData", uniforms.numHairVertices, uniforms.vertexData);
    setUniform3fv("triangleFace", 2, uniforms.triangleFace);
}
