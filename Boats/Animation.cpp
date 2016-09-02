#include "Animation.h"


Animation::Animation()
{
}

Animation::Animation(sf::Texture texture, std::vector<sf::VertexArray> points, float fps)
{
	Create(texture, points, fps);
}

Animation::Animation(sf::Texture texture, sf::Vector2f frameDimentions, float fps)
{
	Create(texture, frameDimentions, fps);
}

Animation::~Animation()
{
}

void Animation::Create(sf::Texture texture, std::vector<sf::VertexArray> points, float fps)
{
	SetTexture(texture);
	SetFrameVec(points);
}

void Animation::Create(sf::Texture texture, sf::Vector2f frameDimentions, float fps)
{
	SetTexture(texture);
	SetDimentions(frameDimentions);
	GenerateFrames();
}

void Animation::Update(float dTime)
{
	m_AnimationTime += dTime;
}

void Animation::AddFrame(sf::VertexArray frame)
{
	m_FramePoints.push_back(frame);
}

void Animation::RemoveFrame(unsigned int index)
{
	m_FramePoints.erase(m_FramePoints.begin() + index);		
}

void Animation::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_Texture;

	unsigned int FrameNumber = m_AnimationTime * m_AnimationFPS;
	FrameNumber %= m_FramePoints.size();	//wrap around to the size of the animation (frame 31 of a 30 frame animation will now be the 1st frame)							

	target.draw(m_FramePoints[FrameNumber], states);
}

sf::Texture Animation::GetTexture()
{
	return m_Texture;
}

std::vector<sf::VertexArray> Animation::GetFrameVec()
{
	return m_FramePoints;
}

sf::Vector2f Animation::GetDimentions()
{
	return m_FrameDimentions;
}

float Animation::GetAnimationFPS()
{
	return m_AnimationFPS;
}

void Animation::SetTexture(sf::Texture val)
{
	m_Texture = val;
}

void Animation::SetFrameVec(std::vector<sf::VertexArray> val)
{
	m_FramePoints = val;
}

void Animation::SetDimentions(sf::Vector2f val)
{
	m_FrameDimentions = val;
}

void Animation::SetAnimatonFPS(float fps)
{
	m_AnimationFPS = fps;
}

void Animation::GenerateFrames()
{
	//The width the height of the texture in FRAMES, not pixles!
	unsigned int m_TextureFramesX = (m_Texture.getSize().x / m_FrameDimentions.x);
	unsigned int m_TextureFramesY = (m_Texture.getSize().y / m_FrameDimentions.y);

	//m_FramePoints.reserve(m_TextureFramesX * m_TextureFramesY);

	for (int i = 0; i < m_TextureFramesY; i++)
	{
		for (int j = 0; j < m_TextureFramesX; j++)
		{
			sf::VertexArray NewFrame(sf::Quads, 4);

			//Points in clockwise order
			NewFrame[0].texCoords = sf::Vector2f(m_FrameDimentions.x * j		, m_FrameDimentions.y * i		);	//top left
			NewFrame[1].texCoords = sf::Vector2f(m_FrameDimentions.x * (j + 1)	, m_FrameDimentions.y * i		);	//top right
			NewFrame[2].texCoords = sf::Vector2f(m_FrameDimentions.x * (j + 1)	, m_FrameDimentions.y * (i + 1));	//bottom right
			NewFrame[3].texCoords = sf::Vector2f(m_FrameDimentions.x * j		, m_FrameDimentions.y * (i + 1));	//bottom left

			NewFrame[0].position = sf::Vector2f(m_FrameDimentions.x * 0, m_FrameDimentions.y * 0);	//top left
			NewFrame[1].position = sf::Vector2f(m_FrameDimentions.x * 1, m_FrameDimentions.y * 0);	//top right
			NewFrame[2].position = sf::Vector2f(m_FrameDimentions.x * 1, m_FrameDimentions.y * 1);	//bottom right
			NewFrame[3].position = sf::Vector2f(m_FrameDimentions.x * 0, m_FrameDimentions.y * 1);	//bottom left

			m_FramePoints.push_back(NewFrame);
		}
	}
}
