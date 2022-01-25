/*
 * Copyright (c) 2022, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _NIM_BLE_LIBRARY_WRAPPER_H_
#define _NIM_BLE_LIBRARY_WRAPPER_H_

#include "IBLELibraryWrapper.h"

struct WrapperPrivateData;

class NimBLELibraryWrapper: public IBLELibraryWrapper {
  public:
    NimBLELibraryWrapper();
    NimBLELibraryWrapper(const NimBLELibraryWrapper& other) = delete;
    NimBLELibraryWrapper& operator=(const NimBLELibraryWrapper& other) = delete;
    virtual ~NimBLELibraryWrapper();
    void init() override;
    void setAdvertisingData(const std::string& data) override;
    void startAdvertising() override;
    void stopAdvertising() override;
    std::string getDeviceAddress() override;

  private:
    void _updateAdvertising();
    static WrapperPrivateData* _data;
    static uint _numberOfInstances;
    void _deinit();
};

#endif /* _NIM_BLE_LIBRARY_WRAPPER_H_ */