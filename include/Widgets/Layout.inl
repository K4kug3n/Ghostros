template<typename T>
inline T* Layout::add_widget(std::unique_ptr<T> widget)
{
	static_assert(std::is_base_of<Widget, T>());
	T* ptr = widget.get();
	m_widgets.emplace_back(std::move(widget));

	return ptr;
}