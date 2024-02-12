#include "Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace FlappyCube
{
	
	std::shared_ptr<spdlog::logger>  Logger::s_EngineLogger;

	void Logger::Init() {

		std::vector<spdlog::sink_ptr> Sinks;
		Sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		Sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("log.txt", true));

		Sinks[0]->set_pattern("[%T] [%^%l%$]	[%n]   	%v");
		Sinks[1]->set_pattern("[%T] [%l]	[%n]   	%v");

		s_EngineLogger = std::make_shared<spdlog::logger>("Engine", begin(Sinks), end(Sinks));
		spdlog::register_logger(s_EngineLogger);
		s_EngineLogger->set_level(spdlog::level::trace);
		s_EngineLogger->flush_on(spdlog::level::trace);

		LOG_INFO("====== New logging session ======");

		if (GetEngineLogger)
		{
			LOG_DEBUG("Log initialization completed.");
		}

	}

	// Set the logging level for the Engine | 0 = Trace, 1 = Debug and 2 = Info.
	void Logger::Set_Engine_LogLevel(int log_level)
	{

		if (log_level == 0) {
			s_EngineLogger->set_level(spdlog::level::trace);
			s_EngineLogger->flush_on(spdlog::level::trace);
			LOG_INFO("Log level has been changed to TRACE");
		}
		if (log_level == 1) {
			s_EngineLogger->set_level(spdlog::level::debug);
			s_EngineLogger->flush_on(spdlog::level::debug);
			LOG_INFO("Log level has been changed to DEBUG");
		}
		if (log_level == 2) {
			s_EngineLogger->set_level(spdlog::level::info);
			s_EngineLogger->flush_on(spdlog::level::info);
			LOG_INFO("Log level has been changed to INFO");
		}
	}
}