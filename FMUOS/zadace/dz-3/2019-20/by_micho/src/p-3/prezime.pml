/*
 * Copyright 2020 Studoši
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define N 35
#define p (x <= 0)

int x = N;

active proctype A() {
do
	:: true ->
		S0: x = x - 4; goto S1;
		S1: x = x + 2; goto S0;
od;
}

active proctype B() {
do
	:: true ->
		S0: x = x - 1; goto S1;
		S1: x = x + 1; goto S0;
od;
}

never  {    /* <>[]p */
T0_init:
        do
        :: ((p)) -> goto accept_S4
        :: (1) -> goto T0_init
        od;
accept_S4:
        do
        :: ((p)) -> goto accept_S4
        od;
}
