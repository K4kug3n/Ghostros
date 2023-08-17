#include "ECS/Components/Node.hpp"

#include <utility>

Node::Node(Vector3f position, Vector2f size)
	: m_position(std::move(position))
	, m_size(std::move(size))
{}

void Node::add_child(Node& child)
{
	m_children.push_back(&child);
}

Vector3f Node::get_center() const
{
	return Vector3f{ m_position.x + m_size.x / 2.f, m_position.y + m_size.y / 2.f, m_position.z };
}

const Vector3f& Node::get_position() const
{
	return m_position;
}

const Vector2f& Node::get_size() const
{
	return m_size;
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
