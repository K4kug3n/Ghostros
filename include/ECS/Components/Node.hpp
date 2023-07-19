#ifndef ECS_COMPONENTS_NODE_HPP
#define ECS_COMPONENTS_NODE_HPP

#include "Maths/Vector3.hpp"

class Node
{
public:
	Node() = delete;
	Node(Vector3f position);
	Node(Node&&) = default;
	Node(const Node&) = delete;
	~Node() = default;

	const Vector3f& get_position() const;
	void move(const Vector3f& movement);
	void set_position(Vector3f position);

	Node& operator=(Node&&) = default;
	Node& operator=(const Node&) = delete;

private: 
	Vector3f m_position;
};

#endif