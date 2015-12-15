/**
 * @file cm_test.c
 * @author Rastislav Szabo <raszabo@cisco.com>, Lukas Macko <lmacko@cisco.com>
 * @brief Connection Manager unit tests.
 *
 * @copyright
 * Copyright 2015 Cisco Systems, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <cmocka.h>

#include "sr_common.h"
#include "connection_manager.h"

static int
setup(void **state) {
    cm_ctx_t *ctx = NULL;

    sr_logger_init(NULL);
    sr_logger_set_level(SR_LL_ERR, SR_LL_ERR); /* print only errors. */

    cm_start("/tmp/sysrepo-test", &ctx);
    *state = ctx;

    return 0;
}

static int
teardown(void **state) {
    //sm_ctx_t *ctx = *state;

    //cm_cleanup(ctx); // TODO
    sr_logger_cleanup();

    return 0;
}

static void
cm_simple(void **state) {
    ;
}

int
main() {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test_setup_teardown(cm_simple, setup, teardown),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}