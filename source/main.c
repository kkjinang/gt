/*
 * Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file main.c
 * @brief Main file of gadget tool.
 * @details Gadget tool is a command line tool for gadget creation and
 * maintenance. Firstly gt needs to parse command line arguments to determine
 * what needs to be done. Then gt just executes a function related to action
 * specified by user.
 */

#include <stdio.h>

#include "parser.h"
#include "executable_command.h"

int main(int argc, const char **av)
{
	const char **argv = av;
	int ret;
	ExecutableCommand cmd;

	gt_parse_commands(argc, argv, &cmd);

	ret = executable_command_exec(&cmd);
	executable_command_clean(&cmd);
	return ret;
}
