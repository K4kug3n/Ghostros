#include "ECS/Components/Node.hpp"

#include <utility>

Node::Node(Vector3f position)
	: m_position(std::move(position))
{}

const Vector3f& Node::get_position() const
{
	return m_position;
}

void Node::move(const Vector3f& movement)
{
	m_position += movement;
}

void Node::set_position(Vector3f position)
{
	m_position = std::move(position);
}
