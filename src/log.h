
#pragma once

#include <cstdio>

#define __loge(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)
#define __logi(fmt, ...) fprintf(stdout, fmt "\n", ##__VA_ARGS__)
