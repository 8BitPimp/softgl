#pragma once
#include "GL.h"

#include <unordered_map>


struct texture_t {

  enum format_t {
    e_argb
  };

  format_t format;
  uint32_t width;
  uint32_t height;
  uint32_t *pixels;

  void release();
};


struct texture_manager_t {

  texture_manager_t() : _bound(0), _uuid(0) {}

  //

  void glTexImage1D(GLenum target, GLint level, GLint internalformat,
                    GLsizei width, GLint border, GLenum format, GLenum type,
                    const GLvoid *pixels);

  void glTexImage2D(GLenum target, GLint level, GLint internalformat,
                    GLsizei width, GLsizei height, GLint border, GLenum format,
                    GLenum type, const GLvoid *pixels);

  //

  void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width,
                       GLenum format, GLenum type, const GLvoid *pixels);

  void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                       GLsizei width, GLsizei height, GLenum format,
                       GLenum type, const GLvoid *pixels);

  //

  void glCopyTexImage1D(GLenum target, GLint level, GLenum internalFormat,
                        GLint x, GLint y, GLsizei width, GLint border);

  void glCopyTexImage2D(GLenum target, GLint level, GLenum internalFormat,
                        GLint x, GLint y, GLsizei width, GLsizei height,
                        GLint border);

  //

  void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x,
                           GLint y, GLsizei width);

  void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset,
                           GLint yoffset, GLint x, GLint y, GLsizei width,
                           GLsizei height);

  void glBindTexture(GLenum target, GLuint texture);

  GLboolean glAreTexturesResident(GLsizei n, const GLuint *textures,
                                  GLboolean *residences);

  void glDeleteTextures(GLsizei n, const GLuint *textures);

  void glGenTextures(GLsizei n, GLuint *textures);

protected:
  uint32_t _bound; // todo: capture target too
  uint32_t _uuid;
  std::unordered_map<uint32_t, struct texture_t*> _tex_map;
};
