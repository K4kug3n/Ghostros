#include "ECS/Components/Node.hpp"

#include <utility>

Node::Node(Vector3f position)
	: position(std::move(position))
{}
