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

# define N 16

mtype = { ini, ack, dreq, data, shutup, quiet, dead };

chan M = [N] of { mtype };
chan W = [N] of { mtype };

active proctype Mproc() {
    W!ini;
    M?ack;
    
    timeout ->
        if
            :: W!shutup
            :: W!dreq;
                M?data ->
                    do
                        :: W!data
                        :: W!shutup;
                        break
                    od
        fi;

    M?shutup;
    W!quiet;
    M?dead
}

active proctype Wproc() {
    W?ini;
    M!ack;
    
    do
        :: W?dreq ->
            M!data
        :: W?data ->
            #if 1
            M!data
            #else
            skip
            #endif
        :: W?shutup ->
            M!shutup;
        break
    od;
    
    W?quiet;
    M!dead
}
