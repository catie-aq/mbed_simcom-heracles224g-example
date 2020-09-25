/*
 * Copyright (c) 2020, CATIE
 * SPDX-License-Identifier: Apache-2.0
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
#include "mbed.h"
#include "common_functions.h"
#include "CellularDevice.h"

namespace {
#define RETRY_COUNT 3
}

NetworkInterface *iface;

/**
 * Connects to the Cellular Network
 */
nsapi_error_t do_connect()
{
    nsapi_error_t retcode = NSAPI_ERROR_OK;
    uint8_t retry_counter = 0;

    printf("connecting...\n");
    while (iface->get_connection_status() != NSAPI_STATUS_GLOBAL_UP) {
        retcode = iface->connect();
        if (retcode == NSAPI_ERROR_AUTH_FAILURE) {
            printf("Authentication Failure. Exiting application\n");
        } else if (retcode == NSAPI_ERROR_OK) {
        	printf("Connection Established.\n");
        } else if (retry_counter > RETRY_COUNT) {
        	printf("Fatal connection failure: %d\n", retcode);
        } else {
        	printf("Couldn't connect: %d, will retry\n", retcode);
            retry_counter++;
            continue;
        }
        break;
    }
    return retcode;
}

int main()
{
    printf("SIMCOM Heracles224G Cellular example\n");

    iface = NetworkInterface::get_default_instance();

    MBED_ASSERT(iface);

    // set cellular default parameters
    iface->set_default_parameters();

    /* Attempt to connect to a cellular network */
	if (do_connect() == NSAPI_ERROR_OK) {
		SocketAddress a;
		iface->get_ip_address(&a);
		printf("IP: %s\n", a.get_ip_address());
	}

    if (iface->disconnect() != NSAPI_ERROR_OK) {
		printf("disconnect failed.\n");
		return -1;
	}
    printf("disconnected\n.");

    // TODO: turn the GSM module off

}
