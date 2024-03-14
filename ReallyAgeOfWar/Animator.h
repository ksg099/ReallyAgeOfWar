#pragma once

enum class AnimationLoopTypes
{
	Single,
	Loop,
	PingPong,
};


struct AnimationFrame
{
	std::string textureId;
	sf::IntRect texCoord;

	AnimationFrame(const std::string& id, const sf::IntRect& coord)
		: textureId(id), texCoord(coord)
	{

	}

	sf::Texture& GetTexture() const
	{
		return RES_MGR_TEXTURE.Get(textureId);
	}
};

struct AnimationClip
{
	//�̺κ� ������
	std::string id;
	int fps = 30;
	AnimationLoopTypes loopType = AnimationLoopTypes::Single;

	std::vector< AnimationFrame> frames;

	int GetTotalFrame() const
	{
		return frames.size();
	}

	bool loadFromFile(const std::string& filePath);
};


struct AnimationEvent
{
	std::string clipId;
	int frame;
	std::function<void()> action; // <��ȯ��(�Ű�����)> ���� ���� ��ȯ�� ���ϰ� �Ű������� �ȹ���
};

class Animator
{
protected:
	//std::unordered_map<std::string, AnimationClip> clips;
	std::queue<std::string> queue; //����� �÷��̾��� ���̵� �־��
	std::list <AnimationEvent> eventList;
	float  speed = 1.f;

	bool isPlaying = false;
	AnimationClip* currentClip = nullptr;
	int totalFrame = 0;
	int currentFrame = -1;
	int addFrame = 1;
	float clipDuration = 0.f;

	float accumTime = 0.f;

	sf::Sprite* target = nullptr;


public:

	Animator();
	~Animator();

	void AddEvent(const std::string& clipId, int frame, std::function<void()> action);
	void ClearEvent();

	sf::Sprite* GetTarget() const { return target; }
	void SetTarget(sf::Sprite* t) { target = t; }

	const std::string& GetCurrentClipId() { return currentClip->id; }
	void SetSpeed(float s) { speed = s; }
	float GetSpeed() const { return speed; }

	bool IsPlaying() const { return isPlaying; }

	//void AddClip(const AnimationClip& clip);
	void SetFrame(const AnimationFrame& frame);
	void Update(float dt);
	void Play(const std::string& clipId, bool clearQueue = true); // ���� ���ϴ� �÷����ϱ�
	void PlayQueue(const std::string& clipId);
	void Stop();
};

