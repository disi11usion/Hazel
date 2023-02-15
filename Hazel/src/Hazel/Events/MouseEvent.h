//
// Created by 吴棋凡 on 2023/2/15.
//

#pragma once

#include "Hazel/Core/MouseCodes.h"
#include "Hazel/Events/Event.h"
namespace Hazel {

class MouseMovedEvent : public Event
{
 public:
  MouseMovedEvent(const float x, const float y)
      : m_MouseX(x), m_MouseY(y) {}

  float GetX() const { return m_MouseX; }
  float GetY() const { return m_MouseY; }

  std::string ToString() const override
  {
    std::stringstream ss;
    ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
    return ss.str();
  }

  EVENT_CLASS_TYPE(MOUSE_MOVED)
  EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)
 private:
  float m_MouseX, m_MouseY;
};

class MouseScrolledEvent : public Event
{
 public:
  MouseScrolledEvent(const float xOffset, const float yOffset)
      : m_XOffset(xOffset), m_YOffset(yOffset) {}

  float GetXOffset() const { return m_XOffset; }
  float GetYOffset() const { return m_YOffset; }

  std::string ToString() const override
  {
    std::stringstream ss;
    ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
    return ss.str();
  }

  EVENT_CLASS_TYPE(MOUSE_SCROLLED)
  EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)
 private:
  float m_XOffset, m_YOffset;
};

class MouseButtonEvent : public Event
{
 public:
  MouseCode GetMouseButton() const { return m_Button; }

  EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT | EVENT_CATEGORY_MOUSE_BUTTON)
 protected:
  MouseButtonEvent(const MouseCode button)
      : m_Button(button) {}

  MouseCode m_Button;
};

class MouseButtonPressedEvent : public MouseButtonEvent
{
 public:
  MouseButtonPressedEvent(const MouseCode button)
      : MouseButtonEvent(button) {}

  std::string ToString() const override
  {
    std::stringstream ss;
    ss << "MouseButtonPressedEvent: " << m_Button;
    return ss.str();
  }

  EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESSED)
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
 public:
  MouseButtonReleasedEvent(const MouseCode button)
      : MouseButtonEvent(button) {}

  std::string ToString() const override
  {
    std::stringstream ss;
    ss << "MouseButtonReleasedEvent: " << m_Button;
    return ss.str();
  }

  EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED)
};

}