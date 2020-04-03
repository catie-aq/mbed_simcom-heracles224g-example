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

int main()
{
    printf("Cellular example\n");

    NetworkInterface *net = NetworkInterface::get_default_instance();
    if (!net) {
        printf("Error! No network inteface found.\n");
        return -1;
    }

    // TODO: Register the network status handler, and implement reconnection logic.

    int connect_err = net->connect();
    if (connect_err) {
        printf("Connection error: %d\n", connect_err);
        return -1;
    }

    SocketAddress a;
    net->get_ip_address(&a);
    printf("IP: %s\n", a.get_ip_address());

    net->disconnect();
    printf("Done\n");
}
