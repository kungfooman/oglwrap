// Copyright (c) 2014, Tamas Csala

/** @file texture_cube.h
    @brief Implements two-dimensional cubeMap textures.
*/

#ifndef OGLWRAP_TEXTURES_TEXTURE_CUBE_H_
#define OGLWRAP_TEXTURES_TEXTURE_CUBE_H_

#include <stdexcept>
#include "texture_base.h"
#include "../enums/texture2D_type.h"
#include "../enums/texture_cube_target.h"

#include "../define_internal_macros.h"

namespace oglwrap {

// -------======{[ TextureCube declaration ]}======-------

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
/// A set of 6 2D textures, that is used to be sampled with 3D direction vectors.
/** @see GL_TEXTURE_CUBE_MAP */
class TextureCube : public TextureBase<TextureType::TextureCubeMap> {
public:
  /// Uploads one a base image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  static void Upload(TextureCubeTarget target,
                     PixelDataInternalFormat internalFormat,
                     GLsizei width,
                     GLsizei height,
                     PixelDataFormat format,
                     PixelDataType type,
                     const void *data) {
    gl(TexImage2D(
      GLenum(target), 0, GLenum(internalFormat), width, height,
      0, GLenum(format), GLenum(type), data
    ));
  }
  /// Uploads one a base image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  BIND_CHECKED void upload(TextureCubeTarget target,
                           PixelDataInternalFormat internalFormat,
                           GLsizei width,
                           GLsizei height,
                           PixelDataFormat format,
                           PixelDataType type,
                           const void *data) const {
    OGLWRAP_CHECK_BINDING();
    Upload(target, internalFormat, width, height, format, type, data);
  }

  /// Uploads a mipmap for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  static void UploadMipmap(TextureCubeTarget target,
                           GLint level,
                           PixelDataInternalFormat internalFormat,
                           GLsizei width,
                           GLsizei height,
                           PixelDataFormat format,
                           PixelDataType type,
                           const void *data) {
    gl(TexImage2D(
      GLenum(target), level, GLenum(internalFormat), width, height,
      0, GLenum(format), GLenum(type), data
    ));
  }
  /// Uploads a mipmap for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  BIND_CHECKED void uploadMipmap(TextureCubeTarget target,
                                 GLint level,
                                 PixelDataInternalFormat internalFormat,
                                 GLsizei width,
                                 GLsizei height,
                                 PixelDataFormat format,
                                 PixelDataType type,
                                 const void *data) const {
    OGLWRAP_CHECK_BINDING();
    UploadMipmap(target, level, internalFormat, width, height, format, type, data);
  }


  /// Updates a part of the base image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param xOffset/yOffset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width/height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  static void SubUpload(TextureCubeTarget target,
                        GLint xOffset,
                        GLint yOffset,
                        GLsizei width,
                        GLsizei height,
                        PixelDataFormat format,
                        PixelDataType type,
                        const void *data) {
    gl(TexSubImage2D(
      GLenum(target), 0, xOffset, yOffset, width, height,
      GLenum(format), GLenum(type), data
    ));
  }
  /// Updates a part of the base image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param xOffset/yOffset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width/height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  BIND_CHECKED void subUpload(TextureCubeTarget target,
                              GLint xOffset,
                              GLint yOffset,
                              GLsizei width,
                              GLsizei height,
                              PixelDataFormat format,
                              PixelDataType type,
                              const void *data) const {
    OGLWRAP_CHECK_BINDING();
    SubUpload(target, xOffset, yOffset, width, height, format, type, data);
  }

  /// Updates a part of a mipmap image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset/yOffset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width/height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  static void SubUploadMipmap(TextureCubeTarget target,
                              GLint level,
                              GLint xOffset,
                              GLint yOffset,
                              GLsizei width,
                              GLsizei height,
                              PixelDataFormat format,
                              PixelDataType type,
                              const void *data) {
    gl(TexSubImage2D(
      GLenum(target), level, xOffset, yOffset,
      width, height, GLenum(format), GLenum(type), data
    ));
  }
  /// Updates a part of a mipmap image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset/yOffset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width/height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  BIND_CHECKED void subUploadMipmap(TextureCubeTarget target,
                                    GLint level,
                                    GLint xOffset,
                                    GLint yOffset,
                                    GLsizei width,
                                    GLsizei height,
                                    PixelDataFormat format,
                                    PixelDataType type,
                                    const void *data) const {
    OGLWRAP_CHECK_BINDING();
    SubUploadMipmap(
      target, level, xOffset, yOffset, width, height, format, type, data
    );
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage2D)
  /// Simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param levels - Specify the number of texture levels.
    * @param internalFormat - Specifies the sized internal format to be used to store texture image data.
    * @param width - Specifies the width of the texture, in texels.
    * @param height - Specifies the height of the texture, in texels. */
  static void Storage(TextureCubeTarget target,
                      GLsizei levels,
                      GLenum internalFormat,
                      GLsizei width,
                      GLsizei height) {
    gl(TexStorage2D(
      GLenum(target), levels, GLenum(internalFormat), width, height
    ));
  }
  /// Simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param levels - Specify the number of texture levels.
    * @param internalFormat - Specifies the sized internal format to be used to store texture image data.
    * @param width - Specifies the width of the texture, in texels.
    * @param height - Specifies the height of the texture, in texels. */
  BIND_CHECKED void storage(TextureCubeTarget target,
                            GLsizei levels,
                            GLenum internalFormat,
                            GLsizei width,
                            GLsizei height) const {
    OGLWRAP_CHECK_BINDING();
    Storage(target, levels, internalFormat, width, height);
  }
#endif // glTexStorage2D

  /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  static void Copy(TextureCubeTarget target,
                   PixelDataInternalFormat internalFormat,
                   GLint x,
                   GLint y,
                   GLsizei width,
                   GLsizei height) {
    gl(CopyTexImage2D(
      GLenum(target), 0, GLenum(internalFormat), x, y, width, height, 0
    ));
  }
  /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  BIND_CHECKED void copy(TextureCubeTarget target,
                         PixelDataInternalFormat internalFormat,
                         GLint x,
                         GLint y,
                         GLsizei width,
                         GLsizei height) const {
    OGLWRAP_CHECK_BINDING();
    Copy(target, internalFormat, x, y, width, height);
  }

  /// Copies pixels from the current GL_READ_BUFFER into a mipmap of one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  static void CopyMipmap(TextureCubeTarget target,
                         GLint level,
                         PixelDataInternalFormat internalFormat,
                         GLint x,
                         GLint y,
                         GLsizei width,
                         GLsizei height) {
    gl(CopyTexImage2D(
      GLenum(target), level, GLenum(internalFormat), x, y, width, height, 0
    ));
  }
  /// Copies pixels from the current GL_READ_BUFFER into a mipmap of one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  BIND_CHECKED void copyMipmap(TextureCubeTarget target,
                               GLint level,
                               PixelDataInternalFormat internalFormat,
                               GLint x,
                               GLint y,
                               GLsizei width,
                               GLsizei height) const {
    OGLWRAP_CHECK_BINDING();
    CopyMipmap(target, level, internalFormat, x, y, width, height);
  }

  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of one side with them.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  static void CopySub(TextureCubeTarget target,
                      GLint xOffset,
                      GLint yOffset,
                      GLint x,
                      GLint y,
                      GLsizei width,
                      GLsizei height) {
    gl(CopyTexSubImage2D(
      GLenum(target), 0, xOffset, yOffset, x, y, width, height
    ));
  }
  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of one side with them.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  BIND_CHECKED void copySub(TextureCubeTarget target,
                            GLint xOffset,
                            GLint yOffset,
                            GLint x,
                            GLint y,
                            GLsizei width,
                            GLsizei height) const {
    OGLWRAP_CHECK_BINDING();
    CopySub(target, xOffset, yOffset, x, y, width, height);
  }

  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  static void CopySubMipmap(TextureCubeTarget target,
                            GLint level,
                            GLint xOffset,
                            GLint yOffset,
                            GLint x,
                            GLint y,
                            GLsizei width,
                            GLsizei height) {
    gl(CopyTexSubImage2D(
      GLenum(target), level, xOffset, yOffset, x, y, width, height
    ));
  }
  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  BIND_CHECKED void copySubMipmap(TextureCubeTarget target,
                                  GLint level,
                                  GLint xOffset,
                                  GLint yOffset,
                                  GLint x,
                                  GLint y,
                                  GLsizei width,
                                  GLsizei height) const {
    OGLWRAP_CHECK_BINDING();
    CopySubMipmap(target, level, xOffset, yOffset, x, y, width, height);
  }

  /// Returns the width of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
  static GLsizei Width(TextureCubeTarget target, GLint level = 0) {
    GLsizei data;
    gl(GetTexLevelParameteriv(GLenum(target), level, GL_TEXTURE_WIDTH, &data));
    return data;
  }
  /// Returns the width of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
  BIND_CHECKED GLsizei width(TextureCubeTarget target, GLint level = 0) const {
    OGLWRAP_CHECK_BINDING();
    return Width(target, level);
  }

  /// Returns the height of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT */
  static GLsizei Height(TextureCubeTarget target, GLint level = 0) {
    GLsizei data;
    gl(GetTexLevelParameteriv(GLenum(target), level, GL_TEXTURE_HEIGHT, &data));
    return data;
  }
  /// Returns the height of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT */
  BIND_CHECKED GLsizei height(TextureCubeTarget target, GLint level = 0) const {
    OGLWRAP_CHECK_BINDING();
    return Height(target, level);
  }

  /// Returns the i-th element of the cube sides in alphabetic order.
  /** @param i - The index of the TextureCubeTarget to return */
  static TextureCubeTarget cubeFace(int i) {
    switch (i) {
      case 0:
        return TextureCubeTarget::TextureCubeMapPositiveX;
      case 1:
        return TextureCubeTarget::TextureCubeMapNegativeX;
      case 2:
        return TextureCubeTarget::TextureCubeMapPositiveY;
      case 3:
        return TextureCubeTarget::TextureCubeMapNegativeY;
      case 4:
        return TextureCubeTarget::TextureCubeMapPositiveZ;
      case 5:
        return TextureCubeTarget::TextureCubeMapNegativeZ;
      default:
        throw std::invalid_argument("CubeFace argument must be between 0 and 5");
    }
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
  /// Return the compressed texture image of one side
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param img - Returns the compressed texture image.
    * @see glGetCompressedTexImage */
  static void GetCompressedImage(TextureCubeTarget target,
                                 GLint level, GLvoid* img) {
    gl(GetCompressedTexImage(GLenum(target), level, img));
  }
  /// Return the compressed texture image of one side
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param img - Returns the compressed texture image.
    * @see glGetCompressedTexImage */
  BIND_CHECKED void getCompressedImage(TextureCubeTarget target,
                                       GLint level, GLvoid* img) const {
    OGLWRAP_CHECK_BINDING();
    GetCompressedImage(target, level, img);
  }
#endif

#if OGLWRAP_USE_IMAGEMAGICK
  /// Loads in, and uploads an image for one side of the cube from a file using Magick++.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param file - Path to the image file.
    * @param format_string - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  static void LoadTexture(TextureCubeTarget target, const std::string& file,
                          std::string format_string = "CSRGBA") {
    try {
      bool srgb{false}, compressed{false};
      size_t s_pos = format_string.find('S');
      if(s_pos != std::string::npos) {
        srgb = true;
        format_string.erase(format_string.begin() + s_pos);
      }
      size_t c_pos = format_string.find('C');
      if(c_pos != std::string::npos) {
        compressed = true;
        format_string.erase(format_string.begin() + c_pos);
      }

      Magick::Image image = Magick::Image(file);
      Magick::Blob blob;
      image.write(&blob, format_string);

      using InternalFormat = PixelDataInternalFormat;
      InternalFormat internal_format =
        srgb ? (compressed ? InternalFormat::CompressedSrgbAlpha :
                             InternalFormat::Srgb8Alpha8) :
               (compressed ? InternalFormat::CompressedRgba :
                             InternalFormat::Rgba8);

      bool bad_alignment = (image.columns() * format_string.length()) % 4 != 0;
      GLint unpack_aligment;

      if(bad_alignment) {
        gl(GetIntegerv(GL_UNPACK_ALIGNMENT, &unpack_aligment));
        gl(PixelStorei(GL_UNPACK_ALIGNMENT, 1));
      }

      Upload(
        target,
        internal_format,
        image.columns(),
        image.rows(),
        PixelDataFormat::Rgba,
        PixelDataType::UnsignedByte,
        blob.data()
      );

      if(bad_alignment) {
        gl(PixelStorei(GL_UNPACK_ALIGNMENT, unpack_aligment));
      }
    } catch(Magick::Error& Error) {
      std::cerr << "Error loading texture: " << Error.what() << std::endl;
    }
  }
  /// Loads in, and uploads an image for one side of the cube from a file using Magick++.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param file - Path to the image file.
    * @param format_string - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  BIND_CHECKED void loadTexture(TextureCubeTarget target, const std::string& file,
                                const std::string& format_string = "CSRGBA") const {
    OGLWRAP_CHECK_BINDING();
    LoadTexture(target, file, format_string);
  }

  /// Loads in, and uploads an image for one side of the cube from a file using Magick++.
  /** @param faceID - Specifies the index of the side to upload. It is usefully to upload all six sides in a for loop.
    * @param file - Path to the image file.
    * @param format_string - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  static void LoadTexture(GLuint faceID, const std::string& file,
                          std::string format_string = "CSRGBA") {
    LoadTexture(cubeFace(faceID), file, format_string);
  }
  /// Loads in, and uploads an image for one side of the cube from a file using Magick++.
  /** @param faceID - Specifies the index of the side to upload. It is usefully to upload all six sides in a for loop.
    * @param file - Path to the image file.
    * @param format_string - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  BIND_CHECKED void loadTexture(GLuint faceID, const std::string& file,
                                const std::string& format_string = "CSRGBA") const {
    OGLWRAP_CHECK_BINDING();
    LoadTexture(faceID, file, format_string);
  }
#endif
}; // End of TextureCube definition

#endif // GL_TEXTURE_CUBE_MAP

} // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif // OGLWRAP_TEXTURES_TEXTURE_CUBE_H_