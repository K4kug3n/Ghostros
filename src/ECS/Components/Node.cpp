#include "ECS/Components/Node.hpp"

#include <utility>

Node::Node(Vector3f position)
	: m_position(std::move(position))
{}

void Node::add_child(Node& child)
{
	m_children.push_back(&child);
}

const Vector3f& Node::get_position() const
{
	return m_position;
}

void Node::move(const Vector3f& movement)
{
	m_position += movement;

	for (auto&& child : m_children)
	{
		child->move(movement);
	}
}

void Node::set_position(Vector3f position)
{
	Vector3f diff = position - m_position;
	for (auto&& child : m_children)
	{
		child->move(diff);
	}

	m_position = std::move(position);
}
