#pragma once

#include <spdlog/spdlog.h>

#include <memory>
#include <string>
#include <vector>

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace FlappyCube
{
	class Logger
	{
	public:
		static void Init();

		static void Set_Engine_LogLevel(int log_level);
		static void Set_Game_LogLevel(int log_level);

		static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		static std::shared_ptr<spdlog::logger>& GetGameLogger() { return s_GameLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_GameLogger;
	};
}

// Core log macros
#define LOG_E_TRACE(...)			FlappyCube::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define LOG_E_DEBUG(...)			FlappyCube::Logger::GetEngineLogger()->debug(__VA_ARGS__)
#define LOG_E_INFO(...)				FlappyCube::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define LOG_E_WARN(...)				FlappyCube::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define LOG_E_ERROR(...)			FlappyCube::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define LOG_E_CRITICAL(...)			FlappyCube::Logger::GetEngineLogger()->critical(__VA_ARGS__)

// Client log macros
#define LOG_G_TRACE(...)			FlappyCube::Logger::GetGameLogger()->trace(__VA_ARGS__)
#define LOG_G_DEBUG(...)			FlappyCube::Logger::GetGameLogger()->debug(__VA_ARGS__)
#define LOG_G_INFO(...)				FlappyCube::Logger::GetGameLogger()->info(__VA_ARGS__)
#define LOG_G_WARN(...)				FlappyCube::Logger::GetGameLogger()->warn(__VA_ARGS__)
#define LOG_G_ERROR(...)			FlappyCube::Logger::GetGameLogger()->error(__VA_ARGS__)
#define LOG_G_CRITICAL(...)			FlappyCube::Logger::GetGameLogger()->critical(__VA_ARGS__)