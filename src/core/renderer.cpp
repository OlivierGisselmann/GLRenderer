#include <core/renderer.hpp>
#include <core/shader.hpp>
#include <utils/logger.hpp>

void message_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar const* message, void const* user_param)
{
	auto const src_str = [source]() {
		switch (source)
		{
		case GL_DEBUG_SOURCE_API: return "API";
		case GL_DEBUG_SOURCE_WINDOW_SYSTEM: return "WINDOW SYSTEM";
		case GL_DEBUG_SOURCE_SHADER_COMPILER: return "SHADER COMPILER";
		case GL_DEBUG_SOURCE_THIRD_PARTY: return "THIRD PARTY";
		case GL_DEBUG_SOURCE_APPLICATION: return "APPLICATION";
		case GL_DEBUG_SOURCE_OTHER: return "OTHER";
        default: return "???";
		}
	}();

	auto const type_str = [type]() {
		switch (type)
		{
		case GL_DEBUG_TYPE_ERROR: return "ERROR";
		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "DEPRECATED_BEHAVIOR";
		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: return "UNDEFINED_BEHAVIOR";
		case GL_DEBUG_TYPE_PORTABILITY: return "PORTABILITY";
		case GL_DEBUG_TYPE_PERFORMANCE: return "PERFORMANCE";
		case GL_DEBUG_TYPE_MARKER: return "MARKER";
		case GL_DEBUG_TYPE_OTHER: return "OTHER";
        default: return "???";
		}
	}();

	auto const severity_str = [severity]() {
		switch (severity) {
		case GL_DEBUG_SEVERITY_NOTIFICATION: return "NOTIFICATION";
		case GL_DEBUG_SEVERITY_LOW: return "LOW";
		case GL_DEBUG_SEVERITY_MEDIUM: return "MEDIUM";
		case GL_DEBUG_SEVERITY_HIGH: return "HIGH";
        default: return "???";
		}
	}();
	std::cout << src_str << ", " << type_str << ", " << severity_str << ", " << id << ": " << message << '\n';
}

renderer::renderer(const renderer_config& config) : m_config(config)
{
    m_window = std::make_unique<window>(m_config.width, m_config.height, m_config.title.c_str(), m_config.resizable);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD");
    
    glViewport(0, 0, m_config.width, m_config.height);

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(message_callback, nullptr);
}

renderer::~renderer()
{
    LOG(logger::DEBUG, "Cleaning renderer");
}

void renderer::render()
{
    std::vector<vertex> v
    {
        {{0.f, .5f, 0.f}, {0.f, 0.f, 1.f}, {0.f, 0.f}},
        {{.5f, -.5f, 0.f}, {0.f, 0.f, 1.f}, {0.f, 0.f}},
        {{-.5f, -.5f, 0.f}, {0.f, 0.f, 1.f}, {0.f, 0.f}}
    };

    std::vector<unsigned int> i {0, 1, 2};
    std::vector<texture> t
    {
        {0, texture::type::DIFFUSE},
        {1, texture::type::SPECULAR}
    };
    
    shader unlit(RESOURCES_PATH"/shaders/unlit.vert", RESOURCES_PATH"/shaders/unlit.frag");

    m_meshes.push_back(std::make_unique<mesh>(v, i, t));

    while (!m_window->should_close())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.f, 0.f, 0.f, 1.f);

        unlit.use();

        for (const auto& msh : m_meshes)
            msh->draw();

        m_window->update();
    }
}