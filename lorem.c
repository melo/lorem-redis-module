#include "redismodule.h"
#include <string.h>

const char *lorem_ipsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

int Ipsum(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
  RedisModule_AutoMemory(ctx);

  if (argc != 1) return RedisModule_WrongArity(ctx);
  
  RedisModuleString *out = RedisModule_CreateString(ctx, lorem_ipsum, strlen(lorem_ipsum));
  
  return RedisModule_ReplyWithString(ctx, out);
}

int RedisModule_OnLoad(RedisModuleCtx *ctx) {
  if (RedisModule_Init(ctx, "lorem", 1, REDISMODULE_APIVER_1) == REDISMODULE_ERR)
    return REDISMODULE_ERR;
  
  if (RedisModule_CreateCommand(ctx, "lorem.ipsum", Ipsum, "readonly", 1, 1, 1) == REDISMODULE_ERR)
    return REDISMODULE_ERR;
  
  return REDISMODULE_OK;
}
