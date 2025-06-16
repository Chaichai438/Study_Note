#include "./include/Log.hpp"

void Log::init()
{
    Logger logger;
    logger.AddPolicy(std::make_shared<ConsoleLogPolicy>());
    logger.AddPolicy(std::make_shared<FileLogPolicy>("app.log"));

    // 记录日志
    logger.Info("System started. Version: {}", 1.2);
    logger.Debug("User {} logged in from {}", "Alice", "192.168.1.10");
    logger.Error("Failed to connect database!");
}