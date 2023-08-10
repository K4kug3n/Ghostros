#ifndef ECS_COMPONENTS_NODE_HPP
#define ECS_COMPONENTS_NODE_HPP

#include <vector>

#include "Maths/Vector3.hpp"

class Node
{
public:
	Node() = delete;
	Node(Vector3f position, Vector2f size);
	Node(Node&&) = default;
	Node(const Node&) = delete;
	~Node() = default;

	void add_child(Node& child);
	const Vector3f& get_center() const;
	const Vector3f& get_position() const;
	const Vector2f& get_size() const;
	void move(const Vector3f& movement);
	void set_position(Vector3f position);

	Node& operator=(Node&&) = default;
	Node& operator=(const Node&) = delete;

private: 
	Vector3f m_position;
	Vector2f m_size;

	std::vector<Node*> m_children;
};

#endif