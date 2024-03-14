#include "pch.h"
#include "Animator.h"

Animator::Animator()
{
}

Animator::~Animator()
{
}

void Animator::AddEvent(const std::string& clipId, int frame, std::function<void()> action)
{
}

void Animator::ClearEvent()
{
}

void Animator::SetFrame(const AnimationFrame& frame)
{
}

void Animator::Update(float dt)
{
}

void Animator::Play(const std::string& clipId, bool clearQueue)
{
}

void Animator::PlayQueue(const std::string& clipId)
{
}

void Animator::Stop()
{
}
