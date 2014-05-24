// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_FRAMEBUFFER_BINDING_H_
#define OGLWRAP_ENUMS_FRAMEBUFFER_BINDING_H_

#include "../config.h"
#include "../debug/binding.h"
#include "framebuffer_type.h"

namespace oglwrap {

inline namespace enums {

enum class FramebufferBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER_BINDING)
  ReadFramebufferBinding = GL_READ_FRAMEBUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER_BINDING)
  DrawFramebufferBinding = GL_DRAW_FRAMEBUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BINDING)
  FramebufferBinding = GL_FRAMEBUFFER_BINDING,
#endif
};

} // enums

inline FramebufferBinding GetBindingTarget(FramebufferType type) {
  FramebufferBinding target;

  switch (type) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER_BINDING) && defined(GL_READ_FRAMEBUFFER)
    case FramebufferType::ReadFramebuffer:
      target = FramebufferBinding::ReadFramebufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_READ_FRAMEBUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER_BINDING) && defined(GL_DRAW_FRAMEBUFFER)
    case FramebufferType::DrawFramebuffer:
      target = FramebufferBinding::DrawFramebufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_DRAW_FRAMEBUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BINDING) && defined(GL_FRAMEBUFFER)
    case FramebufferType::Framebuffer:
      target = FramebufferBinding::FramebufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_FRAMEBUFFER_BINDING";
      break;
#endif
  }

 return target;
}

} // oglwrap

#endif