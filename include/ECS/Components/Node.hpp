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

	Node& operator=(Node&&) = default;
	Node& operator=(const Node&) = delete;

	Vector3f position;
};

#endif