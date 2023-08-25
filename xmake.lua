set_project("CasperBros")

add_requires("sfml", "entt", "nlohmann_json")

add_rules("mode.debug", "mode.release")
add_rules("plugin.vsxmake.autoupdate")

add_includedirs("include")
add_headerfiles("include/**.hpp", "include/**.inl")

set_languages("c++17")
set_warnings("allextra")


target("main")
add_packages("sfml", "entt", "libsdl", "nlohmann_json")
	add_files("src/**.cpp")

	set_rundir("assets")