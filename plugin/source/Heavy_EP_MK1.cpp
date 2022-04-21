/**
 * Copyright (c) 2022 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "Heavy_EP_MK1.hpp"

#include <new>


#define Context(_c) static_cast<Heavy_EP_MK1 *>(_c)


/*
 * Cross-platform aligned alloc
 */

inline void* aligned_alloc_16(size_t size) {
#ifdef _WIN32
    return _aligned_malloc(size, 16);
#elif __APPLE__
    return malloc(size);
#else
    return aligned_alloc(16, size);
#endif
}


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_EP_MK1_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = aligned_alloc_16(sizeof(Heavy_EP_MK1));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_EP_MK1(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_EP_MK1_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = aligned_alloc_16(sizeof(Heavy_EP_MK1));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_EP_MK1(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_EP_MK1_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_EP_MK1();
    // free memory
#ifdef _WIN32
    _aligned_free(instance);
#else
    free(instance);
#endif
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_EP_MK1::Heavy_EP_MK1(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sRPole_init(&sRPole_xQE1l5IP);
  numBytes += sPhasor_k_init(&sPhasor_1g348lth, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_LJ2U55sy);
  numBytes += sLine_init(&sLine_p3apF6qw);
  numBytes += sLine_init(&sLine_Fe0sHHrh);
  numBytes += sBiquad_init(&sBiquad_s_YKOSCulY);
  numBytes += sBiquad_init(&sBiquad_s_WwgL7LgK);
  numBytes += sRPole_init(&sRPole_Yh3y0fv7);
  numBytes += sPhasor_k_init(&sPhasor_fT5BH6mJ, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_OW9MoKMh);
  numBytes += sLine_init(&sLine_hADdbIyX);
  numBytes += sLine_init(&sLine_QOlaVO7i);
  numBytes += sBiquad_init(&sBiquad_s_J2SXmwLe);
  numBytes += sBiquad_init(&sBiquad_s_V1GxOo38);
  numBytes += sRPole_init(&sRPole_fc8fozRB);
  numBytes += sPhasor_k_init(&sPhasor_4cjQsVOb, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_mUTFYoDS);
  numBytes += sLine_init(&sLine_cIX3zJqu);
  numBytes += sLine_init(&sLine_LhlRTRkY);
  numBytes += sBiquad_init(&sBiquad_s_yl5UTiMA);
  numBytes += sBiquad_init(&sBiquad_s_w1lsyZ09);
  numBytes += sRPole_init(&sRPole_6w5YBg62);
  numBytes += sPhasor_k_init(&sPhasor_D5sKYl8D, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_RSpjeLQ7);
  numBytes += sLine_init(&sLine_0sWTZ5AU);
  numBytes += sLine_init(&sLine_RzEGSGrh);
  numBytes += sBiquad_init(&sBiquad_s_RKAk6kYo);
  numBytes += sBiquad_init(&sBiquad_s_tKqK3PD8);
  numBytes += sRPole_init(&sRPole_rortzBCV);
  numBytes += sPhasor_k_init(&sPhasor_EcWjv2sM, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_h1PimpFg);
  numBytes += sLine_init(&sLine_dkF12Ve6);
  numBytes += sLine_init(&sLine_qf13Df9a);
  numBytes += sBiquad_init(&sBiquad_s_5ZyVy244);
  numBytes += sBiquad_init(&sBiquad_s_iY0l9PpE);
  numBytes += sRPole_init(&sRPole_ENY5kCjf);
  numBytes += sPhasor_k_init(&sPhasor_E5G3BDc3, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_FcnY2nUH);
  numBytes += sLine_init(&sLine_7VShF34d);
  numBytes += sLine_init(&sLine_cB6SyVDf);
  numBytes += sBiquad_init(&sBiquad_s_lTst5uXH);
  numBytes += sBiquad_init(&sBiquad_s_bv0ayvgN);
  numBytes += sRPole_init(&sRPole_KtL4KXWw);
  numBytes += sPhasor_k_init(&sPhasor_c7vJg0xU, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_rXfoSWbc);
  numBytes += sLine_init(&sLine_j9bBmCVa);
  numBytes += sLine_init(&sLine_sg8Xev4V);
  numBytes += sBiquad_init(&sBiquad_s_cMP1tQbF);
  numBytes += sBiquad_init(&sBiquad_s_gmGyDRT9);
  numBytes += sRPole_init(&sRPole_hqPZA51z);
  numBytes += sPhasor_k_init(&sPhasor_SazJp6hE, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_i1z0QzqD);
  numBytes += sLine_init(&sLine_B8Rawwja);
  numBytes += sLine_init(&sLine_VEYj3jgK);
  numBytes += sBiquad_init(&sBiquad_s_Tem2knmO);
  numBytes += sBiquad_init(&sBiquad_s_LyFyGR1n);
  numBytes += sRPole_init(&sRPole_FWviEoDV);
  numBytes += sDel1_init(&sDel1_GoFPXWmZ);
  numBytes += cSlice_init(&cSlice_elndZqvG, 2, 1);
  numBytes += cSlice_init(&cSlice_8lQZHtLi, 1, 1);
  numBytes += cSlice_init(&cSlice_YVJyinnD, 0, 1);
  numBytes += cSlice_init(&cSlice_ARpUAMcU, 1, -1);
  numBytes += cSlice_init(&cSlice_qZ4JKRTE, 1, -1);
  numBytes += cVar_init_f(&cVar_cpIi4bZm, 0.0f);
  numBytes += cIf_init(&cIf_YoRQTGhu, false);
  numBytes += cVar_init_f(&cVar_QDfjXuFO, 0.0f);
  numBytes += cIf_init(&cIf_f2jlbKVU, false);
  numBytes += cIf_init(&cIf_mO03xd4v, false);
  numBytes += cIf_init(&cIf_amyuKIUW, false);
  numBytes += cIf_init(&cIf_KcTlrUJx, false);
  numBytes += cIf_init(&cIf_smq6naFn, false);
  numBytes += cPack_init(&cPack_BYT033Zm, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_DhA4et2d, 1, -1);
  numBytes += sVarf_init(&sVarf_RNGFp3NA, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ElxPJUxK, 3.0f);
  numBytes += cBinop_init(&cBinop_BoHvJj3f, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_Yp4JGjbp, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_bjkjROgL, 1, 1);
  numBytes += cSlice_init(&cSlice_X59Ms47y, 0, 1);
  numBytes += cBinop_init(&cBinop_5BolRjUc, 1.0f); // __pow
  numBytes += cDelay_init(this, &cDelay_XJtqLdR3, 2.0f);
  numBytes += cPack_init(&cPack_Tc48KAjO, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_mxHzGYpx, 1, 1);
  numBytes += cSlice_init(&cSlice_S1VOGbss, 0, 1);
  numBytes += cVar_init_f(&cVar_sZ2r4PVf, 22050.0f);
  numBytes += cBinop_init(&cBinop_3RBhQUO2, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_12WWjECf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_JStffWNs, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_LdXQexFY, 2.0f);
  numBytes += cPack_init(&cPack_mCFcgioO, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_Km00ydT2, 1, 1);
  numBytes += cSlice_init(&cSlice_1Q9bVNNN, 0, 1);
  numBytes += cVar_init_f(&cVar_NTVGi1rx, 22050.0f);
  numBytes += cBinop_init(&cBinop_D5D0LaYe, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_MhpLVcYQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dWTru9Kp, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_8PkrkbiL, 1, -1);
  numBytes += cSlice_init(&cSlice_AxhMJRiu, 1, -1);
  numBytes += cBinop_init(&cBinop_AUvUrY4R, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_0vvlNiX4, 44100.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yz2BQm5L, 44100.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_yN9o31WM, 3.0f);
  numBytes += sVarf_init(&sVarf_pkqNsRE6, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_qZFKZiPY, 2.0f);
  numBytes += cDelay_init(this, &cDelay_u4RfWjOf, 3.0f);
  numBytes += cDelay_init(this, &cDelay_HvShZWxN, 3.0f);
  numBytes += cDelay_init(this, &cDelay_62QExDOA, 3.0f);
  numBytes += cDelay_init(this, &cDelay_twfJBpos, 3.0f);
  numBytes += cIf_init(&cIf_uB5Z1HTu, false);
  numBytes += cBinop_init(&cBinop_gRen83wr, 0.0f); // __pow
  numBytes += cPack_init(&cPack_H3oA1KXj, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_H0pkypkT, 2048.0f); // __mul
  numBytes += sVarf_init(&sVarf_5c1hNZPU, -1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mmQmNb4h, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_U88OzJYl, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_E7C2HtOj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_W2qTdReU, 1.0f);
  numBytes += cVar_init_f(&cVar_t9FMWBot, 0.0f);
  numBytes += cSlice_init(&cSlice_0qBP9nWd, 1, -1);
  numBytes += cSlice_init(&cSlice_tESkokbe, 1, -1);
  numBytes += cSlice_init(&cSlice_o4tsP9dq, 1, 1);
  numBytes += cSlice_init(&cSlice_FCBGNY5K, 0, 1);
  numBytes += cVar_init_f(&cVar_nFgGc4Zm, 0.0f);
  numBytes += cIf_init(&cIf_D4wcmJuh, false);
  numBytes += cIf_init(&cIf_c0zUMuUL, false);
  numBytes += cIf_init(&cIf_D3NPspDa, false);
  numBytes += cVar_init_f(&cVar_h9fOsrnu, 0.0f);
  numBytes += cIf_init(&cIf_aU22ke9k, false);
  numBytes += cVar_init_f(&cVar_nFPgN4cq, 0.0f);
  numBytes += cIf_init(&cIf_47eGoYaP, false);
  numBytes += cBinop_init(&cBinop_RBY4x1dy, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_G6zKrSxh, 8.0f);
  numBytes += cTabread_init(&cTabread_PauJffJY, &hTable_jDLA3bj2); // 1148-used
  numBytes += cSlice_init(&cSlice_yetBqfVw, 1, -1);
  numBytes += cVar_init_s(&cVar_TLOWGcxL, "1148-used");
  numBytes += cBinop_init(&cBinop_zGtokhdj, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_KpXSrXsH, &hTable_103Wn1Ed); // 1148-ids
  numBytes += cSlice_init(&cSlice_o3FM47ae, 1, -1);
  numBytes += cVar_init_s(&cVar_5rfRjuLO, "1148-ids");
  numBytes += cBinop_init(&cBinop_FKqtHwiD, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_YQvRzRkM, 0.0f);
  numBytes += cSlice_init(&cSlice_kuLRrEzT, 1, 1);
  numBytes += cSlice_init(&cSlice_zdBnuOil, 0, 1);
  numBytes += cTabread_init(&cTabread_ZQApb8qU, &hTable_zrjAPWjU); // 1148-pitches
  numBytes += cSlice_init(&cSlice_JhRv8Rsb, 1, -1);
  numBytes += cVar_init_s(&cVar_RJ9OHYRE, "1148-pitches");
  numBytes += cBinop_init(&cBinop_anj1Q63b, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_uyfxho1R, 0.0f);
  numBytes += cVar_init_f(&cVar_6P11HIk6, 0.0f);
  numBytes += cIf_init(&cIf_UIdc2Y3S, false);
  numBytes += cTabwrite_init(&cTabwrite_phRkfVNE, &hTable_jDLA3bj2); // 1148-used
  numBytes += cSlice_init(&cSlice_XQ59cW9c, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_srERlrc2, &hTable_103Wn1Ed); // 1148-ids
  numBytes += cSlice_init(&cSlice_92qaa8G2, 1, -1);
  numBytes += cVar_init_f(&cVar_FxOwbdbW, 0.0f);
  numBytes += cVar_init_f(&cVar_qiKMdCfe, 0.0f);
  numBytes += cSlice_init(&cSlice_uEndvnwx, 1, 1);
  numBytes += cSlice_init(&cSlice_IZt7JHNk, 0, 1);
  numBytes += cPack_init(&cPack_81OkRPDa, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_RFdaE8WW, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_7PEtvA9O, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_DNEcWV5z, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_01bWJPHc, 0.0f); // __lt
  numBytes += cIf_init(&cIf_TFIJca8L, false);
  numBytes += cVar_init_f(&cVar_cKm6INBi, 0.0f);
  numBytes += cIf_init(&cIf_ibFYYATN, false);
  numBytes += cVar_init_f(&cVar_QJUrAoEP, 0.0f);
  numBytes += cIf_init(&cIf_o3dHJNrP, false);
  numBytes += cBinop_init(&cBinop_fXXfM7sT, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_YNI0kMWD, 8.0f);
  numBytes += cTabwrite_init(&cTabwrite_4XAIFIT1, &hTable_jDLA3bj2); // 1148-used
  numBytes += cSlice_init(&cSlice_Ahl4XFE1, 1, -1);
  numBytes += cTabread_init(&cTabread_v2Y3w5Js, &hTable_jDLA3bj2); // 1148-used
  numBytes += cSlice_init(&cSlice_KfTlOVnb, 1, -1);
  numBytes += cVar_init_s(&cVar_xlGGAJyo, "1148-used");
  numBytes += cBinop_init(&cBinop_4OhIorOU, 0.0f); // __min
  numBytes += cIf_init(&cIf_9Pnl6QKg, false);
  numBytes += cTabread_init(&cTabread_3p4zBAxb, &hTable_zrjAPWjU); // 1148-pitches
  numBytes += cSlice_init(&cSlice_3TTb2icc, 1, -1);
  numBytes += cVar_init_s(&cVar_ALLgM3kz, "1148-pitches");
  numBytes += cBinop_init(&cBinop_9ycQILEU, 0.0f); // __min
  numBytes += cIf_init(&cIf_4hIlFUU3, false);
  numBytes += cVar_init_f(&cVar_QV1FHuAQ, 0.0f);
  numBytes += cIf_init(&cIf_8SDdSAUy, false);
  numBytes += cVar_init_f(&cVar_OFdGnxYb, 0.0f);
  numBytes += cIf_init(&cIf_iPBiNEnD, false);
  numBytes += cBinop_init(&cBinop_EHSnhdCg, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_gyUPexf9, 8.0f);
  numBytes += cTabwrite_init(&cTabwrite_mwtkLMr5, &hTable_jDLA3bj2); // 1148-used
  numBytes += cSlice_init(&cSlice_687b49wk, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_t4h14qem, &hTable_103Wn1Ed); // 1148-ids
  numBytes += cSlice_init(&cSlice_TpNaIlmR, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_Xc9EqI71, &hTable_zrjAPWjU); // 1148-pitches
  numBytes += cSlice_init(&cSlice_uriW0Yse, 1, -1);
  numBytes += cIf_init(&cIf_N2eqUNfm, false);
  numBytes += cVar_init_f(&cVar_INvadq4g, 0.0f);
  numBytes += cIf_init(&cIf_MXYQ077D, false);
  numBytes += cVar_init_f(&cVar_cdEnC7IL, 0.0f);
  numBytes += cIf_init(&cIf_MuTE4IBy, false);
  numBytes += cBinop_init(&cBinop_fiXM9NS8, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_OkVpRRSw, 8.0f);
  numBytes += cVar_init_f(&cVar_XpmYbjT4, 0.0f);
  numBytes += cIf_init(&cIf_0cDBtrS9, false);
  numBytes += cVar_init_f(&cVar_iiualsly, 0.0f);
  numBytes += cVar_init_f(&cVar_dx2ZQG4K, 0.0f);
  numBytes += cVar_init_f(&cVar_OyUmAZI6, 0.0f);
  numBytes += cIf_init(&cIf_YXo0WfYq, false);
  numBytes += cIf_init(&cIf_dw0Rb8md, false);
  numBytes += cPack_init(&cPack_TGa9AOTT, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_MfvQWInI, 0.0f);
  numBytes += cSlice_init(&cSlice_SvNxgwyv, 1, 1);
  numBytes += cSlice_init(&cSlice_84tpamIM, 0, 1);
  numBytes += cVar_init_f(&cVar_bNgyqWRz, 0.0f);
  numBytes += cIf_init(&cIf_30KS2vcA, false);
  numBytes += cVar_init_f(&cVar_L9vaHYGJ, 0.0f);
  numBytes += cVar_init_f(&cVar_u5tBj8Lb, 0.0f);
  numBytes += cTabread_init(&cTabread_zixFG9DX, &hTable_jDLA3bj2); // 1148-used
  numBytes += cSlice_init(&cSlice_mpKBBGkD, 1, -1);
  numBytes += cVar_init_s(&cVar_qZNKNNj4, "1148-used");
  numBytes += cBinop_init(&cBinop_fTIYVYXR, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_r8YGsDv2, &hTable_103Wn1Ed); // 1148-ids
  numBytes += cSlice_init(&cSlice_E3eGCS7T, 1, -1);
  numBytes += cVar_init_s(&cVar_nqwB3gob, "1148-ids");
  numBytes += cBinop_init(&cBinop_RTJGzepK, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_AFpLtIy7, &hTable_zrjAPWjU); // 1148-pitches
  numBytes += cSlice_init(&cSlice_Xgq2sBvz, 1, -1);
  numBytes += cTabread_init(&cTabread_wzHGlVxe, &hTable_zrjAPWjU); // 1148-pitches
  numBytes += cSlice_init(&cSlice_uQMKeyli, 1, -1);
  numBytes += cVar_init_s(&cVar_6vM6OQsr, "1148-pitches");
  numBytes += cBinop_init(&cBinop_n6HPoGNU, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_7CqRGpzh, &hTable_zrjAPWjU); // 1148-pitches
  numBytes += cSlice_init(&cSlice_fGAlwoVk, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_f431WPJL, &hTable_jDLA3bj2); // 1148-used
  numBytes += cSlice_init(&cSlice_oeypQYGk, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_b1zrUtiJ, &hTable_103Wn1Ed); // 1148-ids
  numBytes += cSlice_init(&cSlice_4y3BMUCB, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_ZnyIyMwB, &hTable_103Wn1Ed); // 1148-ids
  numBytes += cSlice_init(&cSlice_ahe4Nl54, 1, -1);
  numBytes += cVar_init_f(&cVar_GiSxSddZ, 0.0f);
  numBytes += cTabwrite_init(&cTabwrite_rhy4zqC2, &hTable_jDLA3bj2); // 1148-used
  numBytes += cSlice_init(&cSlice_jJFqUT5D, 1, -1);
  numBytes += cVar_init_f(&cVar_MitV4kWM, 0.0f);
  numBytes += cSlice_init(&cSlice_vacnVbtY, 1, 1);
  numBytes += cSlice_init(&cSlice_JP4mGNIp, 0, 1);
  numBytes += cVar_init_f(&cVar_aVw41OwU, 0.0f);
  numBytes += cBinop_init(&cBinop_Bhr229Ht, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_VHLIISwe, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_eieiD2dS, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_wRpWrKWi, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_0TCmOiUi, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_60vLkGOw, 65535.0f); // __unimod
  numBytes += hTable_init(&hTable_zrjAPWjU, 8);
  numBytes += hTable_init(&hTable_jDLA3bj2, 8);
  numBytes += hTable_init(&hTable_103Wn1Ed, 8);
  numBytes += cSlice_init(&cSlice_2INuIXhx, 1, 1);
  numBytes += cSlice_init(&cSlice_rIS4wCWL, 0, 1);
  numBytes += cBinop_init(&cBinop_D4pAxZXo, 1.0f); // __pow
  numBytes += cDelay_init(this, &cDelay_fChR2EMd, 2.0f);
  numBytes += cPack_init(&cPack_5c1776aq, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_uOTUFrWe, 1, 1);
  numBytes += cSlice_init(&cSlice_2v2J5hCG, 0, 1);
  numBytes += cVar_init_f(&cVar_f7mZhooZ, 22050.0f);
  numBytes += cBinop_init(&cBinop_lV6bOwnK, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_WD7C8chd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RcnTHRuu, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_1yRWlMR0, 2.0f);
  numBytes += cPack_init(&cPack_SwGJLASp, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_dtyI5XH4, 1, 1);
  numBytes += cSlice_init(&cSlice_0n4vTued, 0, 1);
  numBytes += cVar_init_f(&cVar_cuvWDrFY, 22050.0f);
  numBytes += cBinop_init(&cBinop_CgfALdqs, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_MfT4ifW4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vp8lIXCn, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_XuiDQjrM, 1, -1);
  numBytes += cSlice_init(&cSlice_jf2Ro2dy, 1, -1);
  numBytes += cBinop_init(&cBinop_JmxewGJv, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_qx7mJTO2, 44100.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Jiw4Es3V, 44100.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_a1Yr3GlD, 3.0f);
  numBytes += sVarf_init(&sVarf_EnIDOsdo, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_odpMaBGc, 2.0f);
  numBytes += cDelay_init(this, &cDelay_zIGcbWr6, 3.0f);
  numBytes += cDelay_init(this, &cDelay_PYqe7fPW, 3.0f);
  numBytes += cDelay_init(this, &cDelay_YTuA3aGI, 3.0f);
  numBytes += cDelay_init(this, &cDelay_B0f8yaM4, 3.0f);
  numBytes += cIf_init(&cIf_drS0YQ1l, false);
  numBytes += cBinop_init(&cBinop_NbhbI6Aw, 0.0f); // __pow
  numBytes += cPack_init(&cPack_nY24jnaO, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_R6mPsfGd, 2048.0f); // __mul
  numBytes += sVarf_init(&sVarf_7rNwdeBI, -1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lvEgPbs3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iDRS34B2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3qDPWnPQ, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_qZT4eBYV, 1, 1);
  numBytes += cSlice_init(&cSlice_7oNej4sG, 0, 1);
  numBytes += cBinop_init(&cBinop_AUKqDMCP, 1.0f); // __pow
  numBytes += cDelay_init(this, &cDelay_ZtwXRUif, 2.0f);
  numBytes += cPack_init(&cPack_J0CLxFll, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_YosQUGW6, 1, 1);
  numBytes += cSlice_init(&cSlice_w1ytFFHJ, 0, 1);
  numBytes += cVar_init_f(&cVar_I5axLBa7, 22050.0f);
  numBytes += cBinop_init(&cBinop_8mUuoz38, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_sChqoevv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_oj8tkGiB, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_iN9nDqKH, 2.0f);
  numBytes += cPack_init(&cPack_XcUCeI3v, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_nOSjeXgq, 1, 1);
  numBytes += cSlice_init(&cSlice_qIBpEnnd, 0, 1);
  numBytes += cVar_init_f(&cVar_6lY50lnm, 22050.0f);
  numBytes += cBinop_init(&cBinop_KyQEhWTY, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_r2nB2y1m, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WSO3zyqT, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_UaT8lPaC, 1, -1);
  numBytes += cSlice_init(&cSlice_F4UGzXJD, 1, -1);
  numBytes += cBinop_init(&cBinop_pNB7bAH5, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_ruyibc4Y, 44100.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zp8XrZmD, 44100.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_QLMdRIRC, 3.0f);
  numBytes += sVarf_init(&sVarf_e5DnsKGN, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_Jj5JoN3X, 2.0f);
  numBytes += cDelay_init(this, &cDelay_MT2IRF44, 3.0f);
  numBytes += cDelay_init(this, &cDelay_kVeglpYz, 3.0f);
  numBytes += cDelay_init(this, &cDelay_HjgtvZoF, 3.0f);
  numBytes += cDelay_init(this, &cDelay_AQqKKBe7, 3.0f);
  numBytes += cIf_init(&cIf_riRtEjEO, false);
  numBytes += cBinop_init(&cBinop_kWGjKN5n, 0.0f); // __pow
  numBytes += cPack_init(&cPack_X3O3xvTy, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_lyVu0twV, 2048.0f); // __mul
  numBytes += sVarf_init(&sVarf_sna6KPtA, -1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1ozkl1Ar, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zeHbGhXt, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NOYgXabI, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_hv3mUgaW, 1, 1);
  numBytes += cSlice_init(&cSlice_XWrWDCcW, 0, 1);
  numBytes += cBinop_init(&cBinop_c0i1xbS9, 1.0f); // __pow
  numBytes += cDelay_init(this, &cDelay_6qAkbHP4, 2.0f);
  numBytes += cPack_init(&cPack_HKhQT7B9, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_FwTqvMn2, 1, 1);
  numBytes += cSlice_init(&cSlice_DcHse9W3, 0, 1);
  numBytes += cVar_init_f(&cVar_r5ixlHEt, 22050.0f);
  numBytes += cBinop_init(&cBinop_HqjECEs6, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_DyUZzAkb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7O0Uks8x, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_fsNbhAVw, 2.0f);
  numBytes += cPack_init(&cPack_8rASSedI, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_SQTrpvHR, 1, 1);
  numBytes += cSlice_init(&cSlice_TEczJAdP, 0, 1);
  numBytes += cVar_init_f(&cVar_9G2w7qnP, 22050.0f);
  numBytes += cBinop_init(&cBinop_wtCPn2v7, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_K4mxXcbU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8A33dqbR, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_MO4iCVh1, 1, -1);
  numBytes += cSlice_init(&cSlice_QuX5M4S2, 1, -1);
  numBytes += cBinop_init(&cBinop_YN6RyC3N, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_LGgQiJgX, 44100.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tfwRhNIy, 44100.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_VB784pvz, 3.0f);
  numBytes += sVarf_init(&sVarf_4WWOmkn4, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_BlyG4Dem, 2.0f);
  numBytes += cDelay_init(this, &cDelay_lesker1N, 3.0f);
  numBytes += cDelay_init(this, &cDelay_xS27Dv4p, 3.0f);
  numBytes += cDelay_init(this, &cDelay_nlscGUxB, 3.0f);
  numBytes += cDelay_init(this, &cDelay_8o62CkX0, 3.0f);
  numBytes += cIf_init(&cIf_eE0PJb50, false);
  numBytes += cBinop_init(&cBinop_dlGEIEnH, 0.0f); // __pow
  numBytes += cPack_init(&cPack_ydX1v6ep, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_av6hA3La, 2048.0f); // __mul
  numBytes += sVarf_init(&sVarf_2h60wK8h, -1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kx1tzfa7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nFQtbdVq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gMuBQaiz, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_jBZVqRID, 1, 1);
  numBytes += cSlice_init(&cSlice_ZxsAnMyr, 0, 1);
  numBytes += cBinop_init(&cBinop_0zmZNoDQ, 1.0f); // __pow
  numBytes += cDelay_init(this, &cDelay_boef1Edm, 2.0f);
  numBytes += cPack_init(&cPack_PKdgj686, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_ZYqqPMEU, 1, 1);
  numBytes += cSlice_init(&cSlice_9r5FvGx8, 0, 1);
  numBytes += cVar_init_f(&cVar_43FOqtBR, 22050.0f);
  numBytes += cBinop_init(&cBinop_sG7uKtCn, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_P4bF2htA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Q2qDb61i, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_0g9RNRzd, 2.0f);
  numBytes += cPack_init(&cPack_zvNQLNNm, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_OT28k0wW, 1, 1);
  numBytes += cSlice_init(&cSlice_dX9iIu2e, 0, 1);
  numBytes += cVar_init_f(&cVar_PQrhAZRa, 22050.0f);
  numBytes += cBinop_init(&cBinop_oqqJ1Paq, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Gzvbv7EO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9lhwrhxA, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_yX2gZFzd, 1, -1);
  numBytes += cSlice_init(&cSlice_WyVXq3I4, 1, -1);
  numBytes += cBinop_init(&cBinop_4gLdkR2v, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_gG3oyfVr, 44100.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LJPeQeRw, 44100.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_ouiGSpqr, 3.0f);
  numBytes += sVarf_init(&sVarf_7P4pkLFI, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_QwttMs34, 2.0f);
  numBytes += cDelay_init(this, &cDelay_ynpjLAAq, 3.0f);
  numBytes += cDelay_init(this, &cDelay_8zQ9g5kN, 3.0f);
  numBytes += cDelay_init(this, &cDelay_S4kddO82, 3.0f);
  numBytes += cDelay_init(this, &cDelay_IMZb3bj3, 3.0f);
  numBytes += cIf_init(&cIf_ZTxZJeNg, false);
  numBytes += cBinop_init(&cBinop_WofbqBHk, 0.0f); // __pow
  numBytes += cPack_init(&cPack_Q2kgvi4X, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_K7pbLD1Z, 2048.0f); // __mul
  numBytes += sVarf_init(&sVarf_3PZoK8Te, -1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4tw7syWZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Uj8v2gts, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QndJgocL, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_YdkTn2WL, 1, 1);
  numBytes += cSlice_init(&cSlice_IDtSoCz3, 0, 1);
  numBytes += cBinop_init(&cBinop_uWnhLLWD, 1.0f); // __pow
  numBytes += cDelay_init(this, &cDelay_LNwKVA6h, 2.0f);
  numBytes += cPack_init(&cPack_TPCSHBXT, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_uN0zKAiB, 1, 1);
  numBytes += cSlice_init(&cSlice_gNyzsSj0, 0, 1);
  numBytes += cVar_init_f(&cVar_mrGWo2hl, 22050.0f);
  numBytes += cBinop_init(&cBinop_6kvx4MW1, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_WdJqQKz5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ya0UY0D5, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_8ZZIXXPz, 2.0f);
  numBytes += cPack_init(&cPack_5500f4rS, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_V7WIm3dA, 1, 1);
  numBytes += cSlice_init(&cSlice_NBtNQH70, 0, 1);
  numBytes += cVar_init_f(&cVar_2nrwCzMG, 22050.0f);
  numBytes += cBinop_init(&cBinop_laWCPJWj, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_QJuMdqAL, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lbmQbBe1, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_QjjpI8v1, 1, -1);
  numBytes += cSlice_init(&cSlice_mq0IVuSG, 1, -1);
  numBytes += cBinop_init(&cBinop_yktdhsb8, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_bwlmwK6X, 44100.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LY96DS0r, 44100.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_FpA49BkW, 3.0f);
  numBytes += sVarf_init(&sVarf_2VaBCHEQ, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_Ksc6L6s1, 2.0f);
  numBytes += cDelay_init(this, &cDelay_HD4QVfFN, 3.0f);
  numBytes += cDelay_init(this, &cDelay_kEuwEux7, 3.0f);
  numBytes += cDelay_init(this, &cDelay_v6eu2VXR, 3.0f);
  numBytes += cDelay_init(this, &cDelay_kJiO8EHE, 3.0f);
  numBytes += cIf_init(&cIf_CxGKJWrF, false);
  numBytes += cBinop_init(&cBinop_gRP0w6t1, 0.0f); // __pow
  numBytes += cPack_init(&cPack_IAED51KK, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_4QbhXBqM, 2048.0f); // __mul
  numBytes += sVarf_init(&sVarf_p9lZuVC3, -1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9dY6u1g9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Tln43Iuf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jkwvGNGq, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_DP57ivEA, 1, 1);
  numBytes += cSlice_init(&cSlice_Jed3KeQW, 0, 1);
  numBytes += cBinop_init(&cBinop_nhMYm0st, 1.0f); // __pow
  numBytes += cDelay_init(this, &cDelay_n7LU68W4, 2.0f);
  numBytes += cPack_init(&cPack_Ty4AZCCD, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_eySO46yn, 1, 1);
  numBytes += cSlice_init(&cSlice_KnxapYvS, 0, 1);
  numBytes += cVar_init_f(&cVar_JD9szZbV, 22050.0f);
  numBytes += cBinop_init(&cBinop_CATg6nPr, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_fNWQjrL4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1LU3jUnE, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_dEFDi52d, 2.0f);
  numBytes += cPack_init(&cPack_uFHXRF1N, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_ADmSntnx, 1, 1);
  numBytes += cSlice_init(&cSlice_S4L3afF2, 0, 1);
  numBytes += cVar_init_f(&cVar_81HDz8CE, 22050.0f);
  numBytes += cBinop_init(&cBinop_l8zt39cL, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_XOZLXNvW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_H49aKc1Z, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_K6SmtxqU, 1, -1);
  numBytes += cSlice_init(&cSlice_BHreXGfs, 1, -1);
  numBytes += cBinop_init(&cBinop_ajNW3u8W, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_tRrgHLef, 44100.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jvcAXwqO, 44100.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_Eru9gouJ, 3.0f);
  numBytes += sVarf_init(&sVarf_wMKdFxWD, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_md93CS7M, 2.0f);
  numBytes += cDelay_init(this, &cDelay_UvgBzaAj, 3.0f);
  numBytes += cDelay_init(this, &cDelay_M1nBpgGs, 3.0f);
  numBytes += cDelay_init(this, &cDelay_9Ftkd6Fy, 3.0f);
  numBytes += cDelay_init(this, &cDelay_8hDBcNPP, 3.0f);
  numBytes += cIf_init(&cIf_BPYXa7JB, false);
  numBytes += cBinop_init(&cBinop_2zKbOLUN, 0.0f); // __pow
  numBytes += cPack_init(&cPack_mmRiOoWd, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_mrXlugiY, 2048.0f); // __mul
  numBytes += sVarf_init(&sVarf_JwE9URmy, -1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kZnFwfGv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uSJzSkBR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OHtE4ZXn, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_kpwhR0tf, 1, 1);
  numBytes += cSlice_init(&cSlice_oh4auhT2, 0, 1);
  numBytes += cBinop_init(&cBinop_0uc0zW84, 1.0f); // __pow
  numBytes += cDelay_init(this, &cDelay_Gn9nia4s, 2.0f);
  numBytes += cPack_init(&cPack_0FFsXUe9, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_UWPDyIY4, 1, 1);
  numBytes += cSlice_init(&cSlice_5Qfl8Kl3, 0, 1);
  numBytes += cVar_init_f(&cVar_kyiC1Zf2, 22050.0f);
  numBytes += cBinop_init(&cBinop_A5QHofQ9, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_yvUDRhOv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4J0MldFm, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_i2j9vtBd, 2.0f);
  numBytes += cPack_init(&cPack_EgibIsHG, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_nx6xWTIv, 1, 1);
  numBytes += cSlice_init(&cSlice_nRibR7JK, 0, 1);
  numBytes += cVar_init_f(&cVar_2ZeHP4qZ, 22050.0f);
  numBytes += cBinop_init(&cBinop_3GYF4I39, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_14rNbRoM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_w0y5ojuv, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_ccZGSBP7, 1, -1);
  numBytes += cSlice_init(&cSlice_Ljp9kzNl, 1, -1);
  numBytes += cBinop_init(&cBinop_CWI2ECk7, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_xbpI8lwe, 44100.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DiXqbjFE, 44100.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_3FZn93hs, 3.0f);
  numBytes += sVarf_init(&sVarf_mprK3PVr, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_rYvigZyQ, 2.0f);
  numBytes += cDelay_init(this, &cDelay_El2I9C77, 3.0f);
  numBytes += cDelay_init(this, &cDelay_IQg5PLnG, 3.0f);
  numBytes += cDelay_init(this, &cDelay_TfNYpGKV, 3.0f);
  numBytes += cDelay_init(this, &cDelay_SQWhXbuK, 3.0f);
  numBytes += cIf_init(&cIf_7NsIHVOW, false);
  numBytes += cBinop_init(&cBinop_JsfiF6qC, 0.0f); // __pow
  numBytes += cPack_init(&cPack_knDzxs63, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_RHSLWQjL, 2048.0f); // __mul
  numBytes += sVarf_init(&sVarf_Zj8nnBuC, -1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QC38XxDe, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_U2PPTpXa, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_71RKkz2i, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_05vVwRGe, 1, -1);
  numBytes += cSlice_init(&cSlice_c3nXiTNC, 1, -1);
  numBytes += cSlice_init(&cSlice_z8G0G5Eb, 1, -1);
  numBytes += cSlice_init(&cSlice_2O5lvYJA, 1, -1);
  numBytes += cSlice_init(&cSlice_if4TiRX7, 1, -1);
  numBytes += cSlice_init(&cSlice_lpM95DRE, 1, -1);
  numBytes += cSlice_init(&cSlice_GQUD4Nul, 1, -1);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_EP_MK1::~Heavy_EP_MK1() {
  cPack_free(&cPack_BYT033Zm);
  cPack_free(&cPack_Tc48KAjO);
  cPack_free(&cPack_mCFcgioO);
  cPack_free(&cPack_H3oA1KXj);
  cPack_free(&cPack_81OkRPDa);
  cPack_free(&cPack_TGa9AOTT);
  hTable_free(&hTable_zrjAPWjU);
  hTable_free(&hTable_jDLA3bj2);
  hTable_free(&hTable_103Wn1Ed);
  cPack_free(&cPack_5c1776aq);
  cPack_free(&cPack_SwGJLASp);
  cPack_free(&cPack_nY24jnaO);
  cPack_free(&cPack_J0CLxFll);
  cPack_free(&cPack_XcUCeI3v);
  cPack_free(&cPack_X3O3xvTy);
  cPack_free(&cPack_HKhQT7B9);
  cPack_free(&cPack_8rASSedI);
  cPack_free(&cPack_ydX1v6ep);
  cPack_free(&cPack_PKdgj686);
  cPack_free(&cPack_zvNQLNNm);
  cPack_free(&cPack_Q2kgvi4X);
  cPack_free(&cPack_TPCSHBXT);
  cPack_free(&cPack_5500f4rS);
  cPack_free(&cPack_IAED51KK);
  cPack_free(&cPack_Ty4AZCCD);
  cPack_free(&cPack_uFHXRF1N);
  cPack_free(&cPack_mmRiOoWd);
  cPack_free(&cPack_0FFsXUe9);
  cPack_free(&cPack_EgibIsHG);
  cPack_free(&cPack_knDzxs63);
}

HvTable *Heavy_EP_MK1::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x15539905: return &hTable_zrjAPWjU; // 1148-pitches
    case 0xFA0C1E3F: return &hTable_jDLA3bj2; // 1148-used
    case 0x6C694DF7: return &hTable_103Wn1Ed; // 1148-ids
    default: return nullptr;
  }
}

void Heavy_EP_MK1::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xFAF44138: { // 1001-buz-pha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MGnMGx0X_sendMessage);
      break;
    }
    case 0x77189A6A: { // 1001-poly
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YUPT5gm3_sendMessage);
      break;
    }
    case 0xC184E4D: { // 1148-currentVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Yvc0SbVa_sendMessage);
      break;
    }
    case 0x9244BCF5: { // 1148-indexOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xWrZfXcb_sendMessage);
      break;
    }
    case 0xAC295247: { // 1148-indexOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_T5RYnxvy_sendMessage);
      break;
    }
    case 0xBD43D8EE: { // 1148-isFirstOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YSOymCGl_sendMessage);
      break;
    }
    case 0x10CBF248: { // 1148-isFirstOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UNQwjlFB_sendMessage);
      break;
    }
    case 0x26D7995C: { // 1148-maxVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VHVO9aGV_sendMessage);
      break;
    }
    case 0x9D529A37: { // 1148-shouldSteal
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_78vPaVrA_sendMessage);
      break;
    }
    case 0x9C33624C: { // 1148-voiceId++
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RehAy77I_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_30ra41Ne_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xufwxl2p_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_EP_MK1::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_EP_MK1::cSlice_elndZqvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_mO03xd4v, 0, m, &cIf_mO03xd4v_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_JhA9xsTS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_8lQZHtLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_smq6naFn, 0, m, &cIf_smq6naFn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_YVJyinnD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSwitchcase_la14mTXi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ARpUAMcU, 0, m, &cSlice_ARpUAMcU_sendMessage);
      break;
    }
    default: {
      cMsg_eoZJvoMh_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_ARpUAMcU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_e7WdcYT3_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      cSwitchcase_e7WdcYT3_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSwitchcase_e7WdcYT3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qZ4JKRTE, 0, m, &cSlice_qZ4JKRTE_sendMessage);
      break;
    }
    default: {
      cMsg_zLbZWnFO_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_qZ4JKRTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_qYBxKwmu_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      cSwitchcase_qYBxKwmu_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_cpIi4bZm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_s8vQ1BWG_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_YoRQTGhu, 0, m, &cIf_YoRQTGhu_sendMessage);
}

void Heavy_EP_MK1::cUnop_eneqfT0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_pCiyJnjZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_mO03xd4v, 1, m, &cIf_mO03xd4v_sendMessage);
}

void Heavy_EP_MK1::cUnop_q0eNViDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_pCiyJnjZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_mO03xd4v, 1, m, &cIf_mO03xd4v_sendMessage);
}

void Heavy_EP_MK1::cIf_YoRQTGhu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_q0eNViDL_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_eneqfT0P_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_s8vQ1BWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YoRQTGhu, 1, m, &cIf_YoRQTGhu_sendMessage);
}

void Heavy_EP_MK1::cVar_QDfjXuFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_TjJdcdK8_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_f2jlbKVU, 0, m, &cIf_f2jlbKVU_sendMessage);
}

void Heavy_EP_MK1::cUnop_E4jP3u4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_9aJebTmn_sendMessage);
}

void Heavy_EP_MK1::cUnop_7Y4zZuNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_9aJebTmn_sendMessage);
}

void Heavy_EP_MK1::cIf_f2jlbKVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_7Y4zZuNv_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_E4jP3u4J_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_TjJdcdK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_f2jlbKVU, 1, m, &cIf_f2jlbKVU_sendMessage);
}

void Heavy_EP_MK1::cIf_mO03xd4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_nFgGc4Zm, 0, m, &cVar_nFgGc4Zm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cIf_amyuKIUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_qYBxKwmu_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cIf_KcTlrUJx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_qYBxKwmu_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cIf_smq6naFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_nFgGc4Zm, 0, m, &cVar_nFgGc4Zm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_9aJebTmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_amyuKIUW, 1, m, &cIf_amyuKIUW_sendMessage);
}

void Heavy_EP_MK1::cBinop_pCiyJnjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KcTlrUJx, 1, m, &cIf_KcTlrUJx_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_smq6naFn, 1, m, &cIf_smq6naFn_sendMessage);
}

void Heavy_EP_MK1::cMsg_nPKwQsvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 2);
  msg_setElementToFrom(m, 2, n, 0);
  cSwitchcase_la14mTXi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_eoZJvoMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 2);
  cIf_onMessage(_c, &Context(_c)->cIf_KcTlrUJx, 0, m, &cIf_KcTlrUJx_sendMessage);
}

void Heavy_EP_MK1::cMsg_zLbZWnFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  cIf_onMessage(_c, &Context(_c)->cIf_amyuKIUW, 0, m, &cIf_amyuKIUW_sendMessage);
}

void Heavy_EP_MK1::cBinop_JhA9xsTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cPack_BYT033Zm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AOX5cBQ7_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSwitchcase_oG9J2dvF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DhA4et2d, 0, m, &cSlice_DhA4et2d_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_DhA4et2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_bjkjROgL, 0, m, &cSlice_bjkjROgL_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_X59Ms47y, 0, m, &cSlice_X59Ms47y_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_bjkjROgL, 0, m, &cSlice_bjkjROgL_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_X59Ms47y, 0, m, &cSlice_X59Ms47y_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_z60tURxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7Hb23T04_sendMessage);
}

void Heavy_EP_MK1::cBinop_7Hb23T04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_k9lbIrHi_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_rz4c8AUf_sendMessage);
}

void Heavy_EP_MK1::cVar_ElxPJUxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_jSKszev7_sendMessage);
}

void Heavy_EP_MK1::cMsg_XSFgs2Vd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1k6xs4ow_sendMessage);
}

void Heavy_EP_MK1::cSystem_1k6xs4ow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BoHvJj3f, HV_BINOP_DIVIDE, 1, m, &cBinop_BoHvJj3f_sendMessage);
}

void Heavy_EP_MK1::cBinop_k9lbIrHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_34r4jXzz_sendMessage);
}

void Heavy_EP_MK1::cBinop_34r4jXzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Yp4JGjbp, m);
}

void Heavy_EP_MK1::cMsg_2ElBnTuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_oX6ssrYL_sendMessage);
}

void Heavy_EP_MK1::cBinop_oX6ssrYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_z60tURxy_sendMessage);
}

void Heavy_EP_MK1::cBinop_rz4c8AUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RNGFp3NA, m);
}

void Heavy_EP_MK1::cBinop_jSKszev7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_vPTjbp6l_sendMessage);
}

void Heavy_EP_MK1::cBinop_vPTjbp6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BoHvJj3f, HV_BINOP_DIVIDE, 0, m, &cBinop_BoHvJj3f_sendMessage);
}

void Heavy_EP_MK1::cBinop_BoHvJj3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2ElBnTuR_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_bjkjROgL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_JuKEhSjI_sendMessage);
      cSwitchcase_dnVPVUlN_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_X59Ms47y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_yN9o31WM, 0, m, &cDelay_yN9o31WM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_qZhFVp8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lzw09MRv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_x7fI6QRT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kmODmaFn_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_1g348lth, 0, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pkqNsRE6, m);
}

void Heavy_EP_MK1::cBinop_puulPVJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_DrdAUms9_sendMessage);
}

void Heavy_EP_MK1::cBinop_DrdAUms9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5BolRjUc, HV_BINOP_POW, 1, m, &cBinop_5BolRjUc_sendMessage);
  cMsg_puiweEqf_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_5BolRjUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_qZhFVp8b_sendMessage);
}

void Heavy_EP_MK1::cMsg_puiweEqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5BolRjUc, HV_BINOP_POW, 0, m, &cBinop_5BolRjUc_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_tPwb42ks_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Y3SeyQLm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Y3SeyQLm_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_XJtqLdR3, 1, m, &cDelay_XJtqLdR3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zyxm9xt4_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_XJtqLdR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XJtqLdR3, m);
  cPack_onMessage(_c, &Context(_c)->cPack_Tc48KAjO, 0, m, &cPack_Tc48KAjO_sendMessage);
}

void Heavy_EP_MK1::cMsg_Y3SeyQLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XJtqLdR3, 0, m, &cDelay_XJtqLdR3_sendMessage);
}

void Heavy_EP_MK1::cCast_zyxm9xt4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XJtqLdR3, 0, m, &cDelay_XJtqLdR3_sendMessage);
}

void Heavy_EP_MK1::cPack_Tc48KAjO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sau9kNWL_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_mxHzGYpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_rt5iICvn_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_S1VOGbss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_mmQmNb4h, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_sZ2r4PVf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3RBhQUO2, HV_BINOP_MULTIPLY, 0, m, &cBinop_3RBhQUO2_sendMessage);
}

void Heavy_EP_MK1::cMsg_iKXnugbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rsdZ4z9K_sendMessage);
}

void Heavy_EP_MK1::cSystem_rsdZ4z9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tjoYH8sh_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_3RBhQUO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_si1yqlyW_sendMessage);
}

void Heavy_EP_MK1::cBinop_k3xOFn9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3RBhQUO2, HV_BINOP_MULTIPLY, 1, m, &cBinop_3RBhQUO2_sendMessage);
}

void Heavy_EP_MK1::cMsg_tjoYH8sh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_k3xOFn9Y_sendMessage);
}

void Heavy_EP_MK1::cBinop_si1yqlyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RceFSyRR_sendMessage);
}

void Heavy_EP_MK1::cBinop_RceFSyRR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ByBj1s2m_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JStffWNs, m);
}

void Heavy_EP_MK1::cBinop_ByBj1s2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_12WWjECf, m);
}

void Heavy_EP_MK1::cSwitchcase_PBqQjRJY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_alTHVTBj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_alTHVTBj_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_LdXQexFY, 1, m, &cDelay_LdXQexFY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q8WBZ5kV_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_LdXQexFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LdXQexFY, m);
  cPack_onMessage(_c, &Context(_c)->cPack_mCFcgioO, 0, m, &cPack_mCFcgioO_sendMessage);
}

void Heavy_EP_MK1::cMsg_alTHVTBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LdXQexFY, 0, m, &cDelay_LdXQexFY_sendMessage);
}

void Heavy_EP_MK1::cCast_q8WBZ5kV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LdXQexFY, 0, m, &cDelay_LdXQexFY_sendMessage);
}

void Heavy_EP_MK1::cPack_mCFcgioO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dkpepr67_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_Km00ydT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_rPtKYy3M_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_1Q9bVNNN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_U88OzJYl, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_NTVGi1rx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D5D0LaYe, HV_BINOP_MULTIPLY, 0, m, &cBinop_D5D0LaYe_sendMessage);
}

void Heavy_EP_MK1::cMsg_JMXe4Ma3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jkVp0Kx6_sendMessage);
}

void Heavy_EP_MK1::cSystem_jkVp0Kx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_h8Wb1BsZ_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_D5D0LaYe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_mTfoFJLO_sendMessage);
}

void Heavy_EP_MK1::cBinop_HA94hCLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D5D0LaYe, HV_BINOP_MULTIPLY, 1, m, &cBinop_D5D0LaYe_sendMessage);
}

void Heavy_EP_MK1::cMsg_h8Wb1BsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_HA94hCLv_sendMessage);
}

void Heavy_EP_MK1::cBinop_mTfoFJLO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_A2KsUGjR_sendMessage);
}

void Heavy_EP_MK1::cBinop_A2KsUGjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_G6AE2PwA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dWTru9Kp, m);
}

void Heavy_EP_MK1::cBinop_G6AE2PwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MhpLVcYQ, m);
}

void Heavy_EP_MK1::cSwitchcase_WUtKOy78_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8PkrkbiL, 0, m, &cSlice_8PkrkbiL_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_AxhMJRiu, 0, m, &cSlice_AxhMJRiu_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_8PkrkbiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_puulPVJ8_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_puulPVJ8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_AxhMJRiu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_aYuF0nQk_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_aYuF0nQk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_Ti73JY9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VFlsIg5P_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QZxtFP7i_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J9xHtT7Q_sendMessage);
}

void Heavy_EP_MK1::cBinop_aYuF0nQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_GBGRcaro_sendMessage);
}

void Heavy_EP_MK1::cBinop_GBGRcaro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AUvUrY4R, HV_BINOP_POW, 1, m, &cBinop_AUvUrY4R_sendMessage);
  cMsg_2BO3w29v_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_AUvUrY4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Ti73JY9X_sendMessage);
}

void Heavy_EP_MK1::cMsg_2BO3w29v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AUvUrY4R, HV_BINOP_POW, 0, m, &cBinop_AUvUrY4R_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_F7qGXQ00_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HSlHEo3Y_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_HSlHEo3Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_82unbjQp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LDzBBnIB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zrinnCdD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OxhalDGO_sendMessage);
  cSwitchcase_qGp4pLv7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_mwVDhc33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iEpbB1Tt_sendMessage);
}

void Heavy_EP_MK1::cSystem_iEpbB1Tt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0vvlNiX4, m);
}

void Heavy_EP_MK1::cMsg_h5Bsj9K4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uncdQ37f_sendMessage);
}

void Heavy_EP_MK1::cSystem_uncdQ37f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yz2BQm5L, m);
}

void Heavy_EP_MK1::cDelay_yN9o31WM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yN9o31WM, m);
  cPack_onMessage(_c, &Context(_c)->cPack_H3oA1KXj, 0, m, &cPack_H3oA1KXj_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_aB1ee6eu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_scaPpHxo_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_scaPpHxo_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_qZFKZiPY, 1, m, &cDelay_qZFKZiPY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L944F4zY_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_qZFKZiPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qZFKZiPY, m);
  cMsg_gFJkvbAL_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_scaPpHxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qZFKZiPY, 0, m, &cDelay_qZFKZiPY_sendMessage);
}

void Heavy_EP_MK1::cCast_L944F4zY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qZFKZiPY, 0, m, &cDelay_qZFKZiPY_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_Iv54fL1f_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_mQ7Y4evj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_mQ7Y4evj_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_u4RfWjOf, 1, m, &cDelay_u4RfWjOf_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ozYOhZf7_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_u4RfWjOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_u4RfWjOf, m);
  cMsg_8vfufbLe_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_mQ7Y4evj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_u4RfWjOf, 0, m, &cDelay_u4RfWjOf_sendMessage);
}

void Heavy_EP_MK1::cCast_ozYOhZf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_u4RfWjOf, 0, m, &cDelay_u4RfWjOf_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_qGp4pLv7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_5za4dMJS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_5za4dMJS_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_HvShZWxN, 1, m, &cDelay_HvShZWxN_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1C4AfEl2_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_HvShZWxN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HvShZWxN, m);
  cMsg_W4073HRq_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_5za4dMJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HvShZWxN, 0, m, &cDelay_HvShZWxN_sendMessage);
}

void Heavy_EP_MK1::cCast_1C4AfEl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HvShZWxN, 0, m, &cDelay_HvShZWxN_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_Gx61poeH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_u88Owd7O_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_u88Owd7O_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_62QExDOA, 1, m, &cDelay_62QExDOA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oZICOJL8_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_62QExDOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_62QExDOA, m);
  cMsg_tNJJ6cBJ_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_u88Owd7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_62QExDOA, 0, m, &cDelay_62QExDOA_sendMessage);
}

void Heavy_EP_MK1::cCast_oZICOJL8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_62QExDOA, 0, m, &cDelay_62QExDOA_sendMessage);
}

void Heavy_EP_MK1::cDelay_twfJBpos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_twfJBpos, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_c85ioJXE_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_dnVPVUlN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DNh0wPJB_sendMessage);
      break;
    }
    default: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_twfJBpos, 0, m, &cDelay_twfJBpos_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_DNh0wPJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cIf_uB5Z1HTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_m0uJKNwI_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_1pfH37j6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cMsg_gp9whmCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gRen83wr, HV_BINOP_POW, 0, m, &cBinop_gRen83wr_sendMessage);
}

void Heavy_EP_MK1::cBinop_gRen83wr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_E7C2HtOj, m);
}

void Heavy_EP_MK1::cBinop_7dajl5bE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_VtqrJbdm_sendMessage);
}

void Heavy_EP_MK1::cCast_HYVll2lR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_maqKW0Ak_sendMessage);
}

void Heavy_EP_MK1::cCast_B2ubKDES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uB5Z1HTu, 0, m, &cIf_uB5Z1HTu_sendMessage);
}

void Heavy_EP_MK1::cBinop_maqKW0Ak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uB5Z1HTu, 1, m, &cIf_uB5Z1HTu_sendMessage);
}

void Heavy_EP_MK1::cBinop_1pfH37j6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_7dajl5bE_sendMessage);
}

void Heavy_EP_MK1::cMsg_m0uJKNwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_E7C2HtOj, m);
}

void Heavy_EP_MK1::cBinop_VtqrJbdm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gRen83wr, HV_BINOP_POW, 1, m, &cBinop_gRen83wr_sendMessage);
  cMsg_gp9whmCc_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cPack_H3oA1KXj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ICgFJaLq_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_JuKEhSjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_F7qGXQ00_onMessage(_c, NULL, 0, m, NULL);
  cPack_onMessage(_c, &Context(_c)->cPack_H3oA1KXj, 1, m, &cPack_H3oA1KXj_sendMessage);
}

void Heavy_EP_MK1::cMsg_pcZ5VfKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_F8TudeNI_sendMessage);
}

void Heavy_EP_MK1::cBinop_F8TudeNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H0pkypkT, HV_BINOP_MULTIPLY, 0, m, &cBinop_H0pkypkT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_dIYEAlww_sendMessage);
}

void Heavy_EP_MK1::cCast_ZnbsczMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_tPwb42ks_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_qnILIr3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hLRXbqS8_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_sau9kNWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_mxHzGYpx, 0, m, &cSlice_mxHzGYpx_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_S1VOGbss, 0, m, &cSlice_S1VOGbss_sendMessage);
}

void Heavy_EP_MK1::cMsg_rt5iICvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_j7sSgKsi_sendMessage);
}

void Heavy_EP_MK1::cBinop_j7sSgKsi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sZ2r4PVf, 0, m, &cVar_sZ2r4PVf_sendMessage);
}

void Heavy_EP_MK1::cMsg_W4073HRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_1g348lth, 1, m);
}

void Heavy_EP_MK1::cBinop_H0pkypkT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Tc48KAjO, 1, m, &cPack_Tc48KAjO_sendMessage);
}

void Heavy_EP_MK1::cCast_82unbjQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Iv54fL1f_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_LDzBBnIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J9NUHt7W_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_J9NUHt7W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_p3apF6qw, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_8vfufbLe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_p3apF6qw, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_7jMyosM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PBqQjRJY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_ZoDeIpFy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tfyjDxKP_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_dkpepr67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Km00ydT2, 0, m, &cSlice_Km00ydT2_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1Q9bVNNN, 0, m, &cSlice_1Q9bVNNN_sendMessage);
}

void Heavy_EP_MK1::cMsg_rPtKYy3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_3tTN8vR3_sendMessage);
}

void Heavy_EP_MK1::cBinop_3tTN8vR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NTVGi1rx, 0, m, &cVar_NTVGi1rx_sendMessage);
}

void Heavy_EP_MK1::cMsg_tfyjDxKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Km00ydT2, 0, m, &cSlice_Km00ydT2_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1Q9bVNNN, 0, m, &cSlice_1Q9bVNNN_sendMessage);
}

void Heavy_EP_MK1::cBinop_dIYEAlww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mCFcgioO, 1, m, &cPack_mCFcgioO_sendMessage);
}

void Heavy_EP_MK1::cMsg_z4lOo8bC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 50.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Km00ydT2, 0, m, &cSlice_Km00ydT2_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1Q9bVNNN, 0, m, &cSlice_1Q9bVNNN_sendMessage);
}

void Heavy_EP_MK1::cCast_J9xHtT7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Tc48KAjO, 0, m, &cPack_Tc48KAjO_sendMessage);
}

void Heavy_EP_MK1::cCast_QZxtFP7i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pcZ5VfKf_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_VFlsIg5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NuZfUb5j_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_x7fI6QRT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pcZ5VfKf_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_kmODmaFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qnILIr3V_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZnbsczMl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZoDeIpFy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7jMyosM4_sendMessage);
}

void Heavy_EP_MK1::cCast_lzw09MRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5SkdkoAS_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_5SkdkoAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2048.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_H0pkypkT, HV_BINOP_MULTIPLY, 1, m, &cBinop_H0pkypkT_sendMessage);
}

void Heavy_EP_MK1::cCast_zrinnCdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Gx61poeH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_OxhalDGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_aB1ee6eu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_tNJJ6cBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Fe0sHHrh, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_gFJkvbAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20000.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Fe0sHHrh, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_hLRXbqS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.1f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_mxHzGYpx, 0, m, &cSlice_mxHzGYpx_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_S1VOGbss, 0, m, &cSlice_S1VOGbss_sendMessage);
}

void Heavy_EP_MK1::cBinop_c85ioJXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 126.0f, 0, m, &cBinop_lklbN5Wj_sendMessage);
}

void Heavy_EP_MK1::cBinop_lklbN5Wj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_33fIYqZl_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_33fIYqZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_7dgfWIsc_sendMessage);
}

void Heavy_EP_MK1::cBinop_7dgfWIsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -30.0f, 0, m, &cBinop_IpPxuID9_sendMessage);
}

void Heavy_EP_MK1::cBinop_IpPxuID9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_XKbyFfP1_sendMessage);
}

void Heavy_EP_MK1::cBinop_XKbyFfP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HYVll2lR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_B2ubKDES_sendMessage);
}

void Heavy_EP_MK1::cMsg_NuZfUb5j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 8.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_H0pkypkT, HV_BINOP_MULTIPLY, 1, m, &cBinop_H0pkypkT_sendMessage);
}

void Heavy_EP_MK1::cMsg_ICgFJaLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_WUtKOy78_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cVar_W2qTdReU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_7AH6hATD_sendMessage);
}

void Heavy_EP_MK1::cVar_t9FMWBot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_60vLkGOw, HV_BINOP_MOD_UNIPOLAR, 0, m, &cBinop_60vLkGOw_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_qYBxKwmu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0qBP9nWd, 0, m, &cSlice_0qBP9nWd_sendMessage);
      break;
    }
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_tESkokbe, 0, m, &cSlice_tESkokbe_sendMessage);
      break;
    }
    default: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_o4tsP9dq, 0, m, &cSlice_o4tsP9dq_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_FCBGNY5K, 0, m, &cSlice_FCBGNY5K_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_0qBP9nWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K8rv8Ljd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Mc8k3hlh_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K8rv8Ljd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Mc8k3hlh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_tESkokbe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kzNTGzTT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tQTbtkm7_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kzNTGzTT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tQTbtkm7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_o4tsP9dq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_nFgGc4Zm, 0, m, &cVar_nFgGc4Zm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_FCBGNY5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_D4wcmJuh, 0, m, &cIf_D4wcmJuh_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_c0zUMuUL, 0, m, &cIf_c0zUMuUL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_nFgGc4Zm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_TGa9AOTT, 1, m, &cPack_TGa9AOTT_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_81OkRPDa, 1, m, &cPack_81OkRPDa_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_aRCf7ezT_sendMessage);
}

void Heavy_EP_MK1::cIf_D4wcmJuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dcDNxpDA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HwYRa9lS_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u85ozOpU_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_TGa9AOTT, 0, m, &cPack_TGa9AOTT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cIf_c0zUMuUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_81OkRPDa, 0, m, &cPack_81OkRPDa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cIf_D3NPspDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_n8meYdCZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1Y4FEehG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_h9fOsrnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZIpKuNn1_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_z1M5xDBU_sendMessage);
}

void Heavy_EP_MK1::cIf_aU22ke9k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8XlFXMki_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AzNh1LS8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_zdLrBU74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aU22ke9k, 1, m, &cIf_aU22ke9k_sendMessage);
}

void Heavy_EP_MK1::cVar_nFPgN4cq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_JAzKubmp_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_47eGoYaP, 0, m, &cIf_47eGoYaP_sendMessage);
}

void Heavy_EP_MK1::cUnop_PXFSc0Xg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_zdLrBU74_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_aU22ke9k, 0, m, &cIf_aU22ke9k_sendMessage);
}

void Heavy_EP_MK1::cUnop_dGHGrDep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_zdLrBU74_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_aU22ke9k, 0, m, &cIf_aU22ke9k_sendMessage);
}

void Heavy_EP_MK1::cIf_47eGoYaP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_dGHGrDep_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_PXFSc0Xg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_JAzKubmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_47eGoYaP, 1, m, &cIf_47eGoYaP_sendMessage);
}

void Heavy_EP_MK1::cCast_z1M5xDBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_D3NPspDa, 0, m, &cIf_D3NPspDa_sendMessage);
}

void Heavy_EP_MK1::cCast_ZIpKuNn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RBY4x1dy, HV_BINOP_LESS_THAN, 0, m, &cBinop_RBY4x1dy_sendMessage);
}

void Heavy_EP_MK1::cBinop_RBY4x1dy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_D3NPspDa, 1, m, &cIf_D3NPspDa_sendMessage);
}

void Heavy_EP_MK1::cCast_8XlFXMki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RBY4x1dy, HV_BINOP_LESS_THAN, 1, m, &cBinop_RBY4x1dy_sendMessage);
}

void Heavy_EP_MK1::cCast_AzNh1LS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hrgvc0UY_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_fiLZbzXB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_h9fOsrnu, 0, m, &cVar_h9fOsrnu_sendMessage);
}

void Heavy_EP_MK1::cMsg_hrgvc0UY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_h9fOsrnu, 0, m, &cVar_h9fOsrnu_sendMessage);
}

void Heavy_EP_MK1::cCast_1Y4FEehG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_fiLZbzXB_sendMessage);
}

void Heavy_EP_MK1::cCast_n8meYdCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_r2Mflo6h_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sjy60rVr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5clhtePq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_t07sRowU_sendMessage);
}

void Heavy_EP_MK1::cVar_G6zKrSxh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nFPgN4cq, 0, m, &cVar_nFPgN4cq_sendMessage);
}

void Heavy_EP_MK1::cTabread_PauJffJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DNEcWV5z, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_DNEcWV5z_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_5yG1TZto_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_yetBqfVw, 0, m, &cSlice_yetBqfVw_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gQEr5Vzf_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qEdTfHLx_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_yetBqfVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_PauJffJY, 1, m, &cTabread_PauJffJY_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_PauJffJY, 1, m, &cTabread_PauJffJY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_TLOWGcxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NacO35R0_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSystem_C94bpPZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_wvx1FFS8_sendMessage);
}

void Heavy_EP_MK1::cBinop_MwEDiNmW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zGtokhdj, HV_BINOP_MIN, 0, m, &cBinop_zGtokhdj_sendMessage);
}

void Heavy_EP_MK1::cCast_qEdTfHLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MwEDiNmW_sendMessage);
}

void Heavy_EP_MK1::cCast_gQEr5Vzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TLOWGcxL, 0, m, &cVar_TLOWGcxL_sendMessage);
}

void Heavy_EP_MK1::cBinop_zGtokhdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_PauJffJY, 0, m, &cTabread_PauJffJY_sendMessage);
}

void Heavy_EP_MK1::cMsg_NacO35R0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_C94bpPZ1_sendMessage);
}

void Heavy_EP_MK1::cBinop_wvx1FFS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zGtokhdj, HV_BINOP_MIN, 1, m, &cBinop_zGtokhdj_sendMessage);
}

void Heavy_EP_MK1::cTabread_KpXSrXsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lVQoNquY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kjGd09sO_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_PAnnPXlJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_o3FM47ae, 0, m, &cSlice_o3FM47ae_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r4xpgQAp_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gjQd6FHg_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_o3FM47ae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_KpXSrXsH, 1, m, &cTabread_KpXSrXsH_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_KpXSrXsH, 1, m, &cTabread_KpXSrXsH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_5rfRjuLO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_da0oVKZL_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSystem_moa8uldG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_GsngWkWj_sendMessage);
}

void Heavy_EP_MK1::cBinop_rQCjjERn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FKqtHwiD, HV_BINOP_MIN, 0, m, &cBinop_FKqtHwiD_sendMessage);
}

void Heavy_EP_MK1::cCast_gjQd6FHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_rQCjjERn_sendMessage);
}

void Heavy_EP_MK1::cCast_r4xpgQAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5rfRjuLO, 0, m, &cVar_5rfRjuLO_sendMessage);
}

void Heavy_EP_MK1::cBinop_FKqtHwiD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_KpXSrXsH, 0, m, &cTabread_KpXSrXsH_sendMessage);
}

void Heavy_EP_MK1::cMsg_da0oVKZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_moa8uldG_sendMessage);
}

void Heavy_EP_MK1::cBinop_GsngWkWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FKqtHwiD, HV_BINOP_MIN, 1, m, &cBinop_FKqtHwiD_sendMessage);
}

void Heavy_EP_MK1::cVar_YQvRzRkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_phRkfVNE, 1, m, &cTabwrite_phRkfVNE_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_srERlrc2, 1, m, &cTabwrite_srERlrc2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qiKMdCfe, 1, m, &cVar_qiKMdCfe_sendMessage);
}

void Heavy_EP_MK1::cSlice_kuLRrEzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_zdBnuOil_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fZQLrPZX_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vqezTY2U_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cTabread_ZQApb8qU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RFdaE8WW, HV_BINOP_EQ, 0, m, &cBinop_RFdaE8WW_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_a59Q0arE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JhRv8Rsb, 0, m, &cSlice_JhRv8Rsb_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wPRiZIlB_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GYSRok7h_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_JhRv8Rsb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_ZQApb8qU, 1, m, &cTabread_ZQApb8qU_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_ZQApb8qU, 1, m, &cTabread_ZQApb8qU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_RJ9OHYRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EfOXUvjM_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSystem_4iejHTOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_t953EdC4_sendMessage);
}

void Heavy_EP_MK1::cBinop_gIbVQO5V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_anj1Q63b, HV_BINOP_MIN, 0, m, &cBinop_anj1Q63b_sendMessage);
}

void Heavy_EP_MK1::cCast_GYSRok7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gIbVQO5V_sendMessage);
}

void Heavy_EP_MK1::cCast_wPRiZIlB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RJ9OHYRE, 0, m, &cVar_RJ9OHYRE_sendMessage);
}

void Heavy_EP_MK1::cBinop_anj1Q63b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_ZQApb8qU, 0, m, &cTabread_ZQApb8qU_sendMessage);
}

void Heavy_EP_MK1::cMsg_EfOXUvjM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4iejHTOR_sendMessage);
}

void Heavy_EP_MK1::cBinop_t953EdC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_anj1Q63b, HV_BINOP_MIN, 1, m, &cBinop_anj1Q63b_sendMessage);
}

void Heavy_EP_MK1::cVar_uyfxho1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_01bWJPHc, HV_BINOP_LESS_THAN, 1, m, &cBinop_01bWJPHc_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_5744zJoT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nl7RC4Js_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_nl7RC4Js_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_otsptKoG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OiE13JrK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Toelep2C_sendMessage);
}

void Heavy_EP_MK1::cVar_6P11HIk6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_01bWJPHc, HV_BINOP_LESS_THAN, 1, m, &cBinop_01bWJPHc_sendMessage);
}

void Heavy_EP_MK1::cIf_UIdc2Y3S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oaX9amtS_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lC8f8LIc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZP0FUoSx_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_uEndvnwx, 0, m, &cSlice_uEndvnwx_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_IZt7JHNk, 0, m, &cSlice_IZt7JHNk_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JZbX8B3e_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cTabwrite_phRkfVNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cSwitchcase_IUt7eNhX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XQ59cW9c, 0, m, &cSlice_XQ59cW9c_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_phRkfVNE, 0, m, &cTabwrite_phRkfVNE_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_XQ59cW9c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_phRkfVNE, 2, m, &cTabwrite_phRkfVNE_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_phRkfVNE, 2, m, &cTabwrite_phRkfVNE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cTabwrite_srERlrc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cSwitchcase_XRXMyVgf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_92qaa8G2, 0, m, &cSlice_92qaa8G2_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_srERlrc2, 0, m, &cTabwrite_srERlrc2_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_92qaa8G2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_srERlrc2, 2, m, &cTabwrite_srERlrc2_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_srERlrc2, 2, m, &cTabwrite_srERlrc2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_FxOwbdbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XRXMyVgf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cVar_qiKMdCfe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_EpXBdGxj_sendMessage);
}

void Heavy_EP_MK1::cSlice_uEndvnwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_IZt7JHNk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_BYT033Zm, 1, m, &cPack_BYT033Zm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cPack_81OkRPDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_59ayNLj0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zxoReFHB_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_kuLRrEzT, 0, m, &cSlice_kuLRrEzT_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_zdBnuOil, 0, m, &cSlice_zdBnuOil_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_UIdc2Y3S, 0, m, &cIf_UIdc2Y3S_sendMessage);
}

void Heavy_EP_MK1::cCast_t07sRowU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_a59Q0arE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_sjy60rVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PAnnPXlJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_r2Mflo6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YQvRzRkM, 1, m, &cVar_YQvRzRkM_sendMessage);
}

void Heavy_EP_MK1::cCast_5clhtePq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5yG1TZto_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_xgIdlh3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_UIdc2Y3S, 1, m, &cIf_UIdc2Y3S_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YQvRzRkM, 0, m, &cVar_YQvRzRkM_sendMessage);
}

void Heavy_EP_MK1::cMsg_DEENwYXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_UIdc2Y3S, 1, m, &cIf_UIdc2Y3S_sendMessage);
}

void Heavy_EP_MK1::cCast_zxoReFHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xgIdlh3q_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_59ayNLj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uyfxho1R, 0, m, &cVar_uyfxho1R_sendMessage);
}

void Heavy_EP_MK1::cCast_fZQLrPZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RFdaE8WW, HV_BINOP_EQ, 1, m, &cBinop_RFdaE8WW_sendMessage);
}

void Heavy_EP_MK1::cCast_vqezTY2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_G6zKrSxh, 0, m, &cVar_G6zKrSxh_sendMessage);
}

void Heavy_EP_MK1::cBinop_RFdaE8WW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7PEtvA9O, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_7PEtvA9O_sendMessage);
}

void Heavy_EP_MK1::cBinop_7PEtvA9O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5744zJoT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cBinop_DNEcWV5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7PEtvA9O, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_7PEtvA9O_sendMessage);
}

void Heavy_EP_MK1::cBinop_01bWJPHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DNEcWV5z, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_DNEcWV5z_sendMessage);
}

void Heavy_EP_MK1::cCast_Toelep2C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YQvRzRkM, 0, m, &cVar_YQvRzRkM_sendMessage);
}

void Heavy_EP_MK1::cCast_otsptKoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6P11HIk6, 0, m, &cVar_6P11HIk6_sendMessage);
}

void Heavy_EP_MK1::cCast_OiE13JrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DEENwYXO_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_kjGd09sO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_01bWJPHc, HV_BINOP_LESS_THAN, 0, m, &cBinop_01bWJPHc_sendMessage);
}

void Heavy_EP_MK1::cCast_lVQoNquY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6P11HIk6, 1, m, &cVar_6P11HIk6_sendMessage);
}

void Heavy_EP_MK1::cCast_v3d0oOQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FxOwbdbW, 0, m, &cVar_FxOwbdbW_sendMessage);
}

void Heavy_EP_MK1::cCast_tT8xPc3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_NjIhZ7gk_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSend_NjIhZ7gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RehAy77I_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_lC8f8LIc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tT8xPc3T_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v3d0oOQA_sendMessage);
}

void Heavy_EP_MK1::cCast_oaX9amtS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M9vQGpYc_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_M9vQGpYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_IUt7eNhX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_ZP0FUoSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d5XuoGTL_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_JZbX8B3e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qiKMdCfe, 0, m, &cVar_qiKMdCfe_sendMessage);
}

void Heavy_EP_MK1::cMsg_d5XuoGTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_BYT033Zm, 2, m, &cPack_BYT033Zm_sendMessage);
}

void Heavy_EP_MK1::cIf_TFIJca8L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_O4Q1pV7f_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_L0r15hIm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_cKm6INBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OsZGs13Y_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d65Rxi8V_sendMessage);
}

void Heavy_EP_MK1::cIf_ibFYYATN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Tz96PA7l_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zbdsGp4Q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_I8mRYXHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ibFYYATN, 1, m, &cIf_ibFYYATN_sendMessage);
}

void Heavy_EP_MK1::cVar_QJUrAoEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_3kgvdtIu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_o3dHJNrP, 0, m, &cIf_o3dHJNrP_sendMessage);
}

void Heavy_EP_MK1::cUnop_txyu0gVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_I8mRYXHG_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ibFYYATN, 0, m, &cIf_ibFYYATN_sendMessage);
}

void Heavy_EP_MK1::cUnop_sJpF83hS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_I8mRYXHG_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ibFYYATN, 0, m, &cIf_ibFYYATN_sendMessage);
}

void Heavy_EP_MK1::cIf_o3dHJNrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_sJpF83hS_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_txyu0gVn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_3kgvdtIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_o3dHJNrP, 1, m, &cIf_o3dHJNrP_sendMessage);
}

void Heavy_EP_MK1::cCast_OsZGs13Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fXXfM7sT, HV_BINOP_LESS_THAN, 0, m, &cBinop_fXXfM7sT_sendMessage);
}

void Heavy_EP_MK1::cCast_d65Rxi8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TFIJca8L, 0, m, &cIf_TFIJca8L_sendMessage);
}

void Heavy_EP_MK1::cBinop_fXXfM7sT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TFIJca8L, 1, m, &cIf_TFIJca8L_sendMessage);
}

void Heavy_EP_MK1::cCast_Tz96PA7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fXXfM7sT, HV_BINOP_LESS_THAN, 1, m, &cBinop_fXXfM7sT_sendMessage);
}

void Heavy_EP_MK1::cCast_zbdsGp4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PwyvfUkq_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_CDRpKtNX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cKm6INBi, 0, m, &cVar_cKm6INBi_sendMessage);
}

void Heavy_EP_MK1::cMsg_PwyvfUkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_cKm6INBi, 0, m, &cVar_cKm6INBi_sendMessage);
}

void Heavy_EP_MK1::cCast_O4Q1pV7f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BABcar8i_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IlvONaEH_sendMessage);
}

void Heavy_EP_MK1::cCast_L0r15hIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_CDRpKtNX_sendMessage);
}

void Heavy_EP_MK1::cVar_YNI0kMWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QJUrAoEP, 0, m, &cVar_QJUrAoEP_sendMessage);
}

void Heavy_EP_MK1::cTabwrite_4XAIFIT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cSwitchcase_svMWwU5f_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ahl4XFE1, 0, m, &cSlice_Ahl4XFE1_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_4XAIFIT1, 0, m, &cTabwrite_4XAIFIT1_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_Ahl4XFE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_4XAIFIT1, 2, m, &cTabwrite_4XAIFIT1_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_4XAIFIT1, 2, m, &cTabwrite_4XAIFIT1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cTabread_v2Y3w5Js_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_akFH16AP_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_skQ75NR9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KfTlOVnb, 0, m, &cSlice_KfTlOVnb_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T1P9TfNh_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YrH7suTO_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_KfTlOVnb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_v2Y3w5Js, 1, m, &cTabread_v2Y3w5Js_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_v2Y3w5Js, 1, m, &cTabread_v2Y3w5Js_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_xlGGAJyo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cgmV7hzj_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSystem_pnjlb28E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_zrolu0CB_sendMessage);
}

void Heavy_EP_MK1::cBinop_mGNHy9HX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4OhIorOU, HV_BINOP_MIN, 0, m, &cBinop_4OhIorOU_sendMessage);
}

void Heavy_EP_MK1::cCast_YrH7suTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mGNHy9HX_sendMessage);
}

void Heavy_EP_MK1::cCast_T1P9TfNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xlGGAJyo, 0, m, &cVar_xlGGAJyo_sendMessage);
}

void Heavy_EP_MK1::cBinop_4OhIorOU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_v2Y3w5Js, 0, m, &cTabread_v2Y3w5Js_sendMessage);
}

void Heavy_EP_MK1::cMsg_cgmV7hzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pnjlb28E_sendMessage);
}

void Heavy_EP_MK1::cBinop_zrolu0CB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4OhIorOU, HV_BINOP_MIN, 1, m, &cBinop_4OhIorOU_sendMessage);
}

void Heavy_EP_MK1::cIf_9Pnl6QKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ACsUUs03_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Pwj4c9ij_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Y55V3JXd_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TB6jVJx0_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iN9dXiS0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cTabread_3p4zBAxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BYT033Zm, 1, m, &cPack_BYT033Zm_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_D3NrhQzb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3TTb2icc, 0, m, &cSlice_3TTb2icc_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_moRgLKdQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2PhtqbJs_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_3TTb2icc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_3p4zBAxb, 1, m, &cTabread_3p4zBAxb_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_3p4zBAxb, 1, m, &cTabread_3p4zBAxb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_ALLgM3kz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z15Lktot_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSystem_toydDMEZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_cWTIXbmQ_sendMessage);
}

void Heavy_EP_MK1::cBinop_x6QzRkvq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9ycQILEU, HV_BINOP_MIN, 0, m, &cBinop_9ycQILEU_sendMessage);
}

void Heavy_EP_MK1::cCast_2PhtqbJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_x6QzRkvq_sendMessage);
}

void Heavy_EP_MK1::cCast_moRgLKdQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ALLgM3kz, 0, m, &cVar_ALLgM3kz_sendMessage);
}

void Heavy_EP_MK1::cBinop_9ycQILEU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_3p4zBAxb, 0, m, &cTabread_3p4zBAxb_sendMessage);
}

void Heavy_EP_MK1::cMsg_Z15Lktot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_toydDMEZ_sendMessage);
}

void Heavy_EP_MK1::cBinop_cWTIXbmQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9ycQILEU, HV_BINOP_MIN, 1, m, &cBinop_9ycQILEU_sendMessage);
}

void Heavy_EP_MK1::cCast_K8rv8Ljd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FqNyPWwF_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_Mc8k3hlh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YNI0kMWD, 0, m, &cVar_YNI0kMWD_sendMessage);
}

void Heavy_EP_MK1::cMsg_FqNyPWwF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_hiyIT3I9_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSend_hiyIT3I9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RehAy77I_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_akFH16AP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9Pnl6QKg, 1, m, &cIf_9Pnl6QKg_sendMessage);
}

void Heavy_EP_MK1::cCast_IlvONaEH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9Pnl6QKg, 0, m, &cIf_9Pnl6QKg_sendMessage);
}

void Heavy_EP_MK1::cCast_BABcar8i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_skQ75NR9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_lx0ou6gW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_BYT033Zm, 2, m, &cPack_BYT033Zm_sendMessage);
}

void Heavy_EP_MK1::cCast_Pwj4c9ij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_D3NrhQzb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_iN9dXiS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HkQLUnNC_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_TB6jVJx0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OVwLKMkd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cCLqsJUy_sendMessage);
}

void Heavy_EP_MK1::cCast_Y55V3JXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_EpXBdGxj_sendMessage);
}

void Heavy_EP_MK1::cCast_ACsUUs03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lx0ou6gW_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_cCLqsJUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GbFwLbYr_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_OVwLKMkd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_4XAIFIT1, 1, m, &cTabwrite_4XAIFIT1_sendMessage);
}

void Heavy_EP_MK1::cMsg_GbFwLbYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_svMWwU5f_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cSend_HkQLUnNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RehAy77I_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cIf_4hIlFUU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hERdrwbZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rorsqFcn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_QV1FHuAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_E7hj1L6l_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6K1GAY3K_sendMessage);
}

void Heavy_EP_MK1::cIf_8SDdSAUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2a8a6rMB_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_syhavs5K_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_tf6cjDqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8SDdSAUy, 1, m, &cIf_8SDdSAUy_sendMessage);
}

void Heavy_EP_MK1::cVar_OFdGnxYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_X0hsC581_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_iPBiNEnD, 0, m, &cIf_iPBiNEnD_sendMessage);
}

void Heavy_EP_MK1::cUnop_HQuF2Uw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_tf6cjDqo_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_8SDdSAUy, 0, m, &cIf_8SDdSAUy_sendMessage);
}

void Heavy_EP_MK1::cUnop_MChGy2fT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_tf6cjDqo_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_8SDdSAUy, 0, m, &cIf_8SDdSAUy_sendMessage);
}

void Heavy_EP_MK1::cIf_iPBiNEnD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_MChGy2fT_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HQuF2Uw5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_X0hsC581_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iPBiNEnD, 1, m, &cIf_iPBiNEnD_sendMessage);
}

void Heavy_EP_MK1::cCast_E7hj1L6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EHSnhdCg, HV_BINOP_LESS_THAN, 0, m, &cBinop_EHSnhdCg_sendMessage);
}

void Heavy_EP_MK1::cCast_6K1GAY3K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4hIlFUU3, 0, m, &cIf_4hIlFUU3_sendMessage);
}

void Heavy_EP_MK1::cBinop_EHSnhdCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4hIlFUU3, 1, m, &cIf_4hIlFUU3_sendMessage);
}

void Heavy_EP_MK1::cCast_2a8a6rMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EHSnhdCg, HV_BINOP_LESS_THAN, 1, m, &cBinop_EHSnhdCg_sendMessage);
}

void Heavy_EP_MK1::cCast_syhavs5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wL2IEA7O_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_oBnn7Qpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QV1FHuAQ, 0, m, &cVar_QV1FHuAQ_sendMessage);
}

void Heavy_EP_MK1::cMsg_wL2IEA7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_QV1FHuAQ, 0, m, &cVar_QV1FHuAQ_sendMessage);
}

void Heavy_EP_MK1::cCast_rorsqFcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_oBnn7Qpa_sendMessage);
}

void Heavy_EP_MK1::cCast_hERdrwbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Xc9EqI71, 1, m, &cTabwrite_Xc9EqI71_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_t4h14qem, 1, m, &cTabwrite_t4h14qem_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_mwtkLMr5, 1, m, &cTabwrite_mwtkLMr5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GHLt8WPI_sendMessage);
}

void Heavy_EP_MK1::cVar_gyUPexf9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OFdGnxYb, 0, m, &cVar_OFdGnxYb_sendMessage);
}

void Heavy_EP_MK1::cTabwrite_mwtkLMr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cSwitchcase_vE84ra0Q_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_687b49wk, 0, m, &cSlice_687b49wk_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_mwtkLMr5, 0, m, &cTabwrite_mwtkLMr5_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_687b49wk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_mwtkLMr5, 2, m, &cTabwrite_mwtkLMr5_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_mwtkLMr5, 2, m, &cTabwrite_mwtkLMr5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cTabwrite_t4h14qem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cSwitchcase_o5Iw8aY4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TpNaIlmR, 0, m, &cSlice_TpNaIlmR_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_t4h14qem, 0, m, &cTabwrite_t4h14qem_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_TpNaIlmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_t4h14qem, 2, m, &cTabwrite_t4h14qem_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_t4h14qem, 2, m, &cTabwrite_t4h14qem_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cTabwrite_Xc9EqI71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cSwitchcase_qxoy524G_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_uriW0Yse, 0, m, &cSlice_uriW0Yse_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Xc9EqI71, 0, m, &cTabwrite_Xc9EqI71_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_uriW0Yse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Xc9EqI71, 2, m, &cTabwrite_Xc9EqI71_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Xc9EqI71, 2, m, &cTabwrite_Xc9EqI71_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cMsg_wJpP8g92_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_qxoy524G_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_o5Iw8aY4_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_vE84ra0Q_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_tQTbtkm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gyUPexf9, 0, m, &cVar_gyUPexf9_sendMessage);
}

void Heavy_EP_MK1::cCast_kzNTGzTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oeYJ9kzZ_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_oeYJ9kzZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_pZhDrNel_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSend_pZhDrNel_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RehAy77I_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_GHLt8WPI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wJpP8g92_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cIf_N2eqUNfm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eSt1Myvl_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zHPXM7Vo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_INvadq4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M0vsPpvk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Aeno7EE6_sendMessage);
}

void Heavy_EP_MK1::cIf_MXYQ077D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_L1fYJdEq_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WoShzqey_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_UT1t4ZTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MXYQ077D, 1, m, &cIf_MXYQ077D_sendMessage);
}

void Heavy_EP_MK1::cVar_cdEnC7IL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Tgf0gGqC_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_MuTE4IBy, 0, m, &cIf_MuTE4IBy_sendMessage);
}

void Heavy_EP_MK1::cUnop_tyiyS93M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_UT1t4ZTo_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_MXYQ077D, 0, m, &cIf_MXYQ077D_sendMessage);
}

void Heavy_EP_MK1::cUnop_rQdaBRHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_UT1t4ZTo_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_MXYQ077D, 0, m, &cIf_MXYQ077D_sendMessage);
}

void Heavy_EP_MK1::cIf_MuTE4IBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_rQdaBRHs_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tyiyS93M_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_Tgf0gGqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MuTE4IBy, 1, m, &cIf_MuTE4IBy_sendMessage);
}

void Heavy_EP_MK1::cCast_M0vsPpvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fiXM9NS8, HV_BINOP_LESS_THAN, 0, m, &cBinop_fiXM9NS8_sendMessage);
}

void Heavy_EP_MK1::cCast_Aeno7EE6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_N2eqUNfm, 0, m, &cIf_N2eqUNfm_sendMessage);
}

void Heavy_EP_MK1::cBinop_fiXM9NS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_N2eqUNfm, 1, m, &cIf_N2eqUNfm_sendMessage);
}

void Heavy_EP_MK1::cCast_L1fYJdEq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fiXM9NS8, HV_BINOP_LESS_THAN, 1, m, &cBinop_fiXM9NS8_sendMessage);
}

void Heavy_EP_MK1::cCast_WoShzqey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JMY8MiET_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_2rzB3hZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_INvadq4g, 0, m, &cVar_INvadq4g_sendMessage);
}

void Heavy_EP_MK1::cMsg_JMY8MiET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_INvadq4g, 0, m, &cVar_INvadq4g_sendMessage);
}

void Heavy_EP_MK1::cCast_eSt1Myvl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Rqdzzopc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QKm7gW5N_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pRnu6zXa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MzF5Hl3g_sendMessage);
}

void Heavy_EP_MK1::cCast_zHPXM7Vo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_2rzB3hZ9_sendMessage);
}

void Heavy_EP_MK1::cVar_OkVpRRSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cdEnC7IL, 0, m, &cVar_cdEnC7IL_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_lEtY4E6Y_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DuaZN2LR_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_DuaZN2LR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IQbanAHu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Xlp3vC4h_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A5avvMDt_sendMessage);
}

void Heavy_EP_MK1::cVar_XpmYbjT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_yCYNWwSA_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cIf_0cDBtrS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_1LrlSH8t_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_iiualsly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_WSDDndNM_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSwitchcase_1LrlSH8t_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LyTrBvaL_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_LyTrBvaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yVBkpDUK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lzcrmloV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yyCIcfT1_sendMessage);
}

void Heavy_EP_MK1::cVar_dx2ZQG4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VHLIISwe, HV_BINOP_LESS_THAN, 1, m, &cBinop_VHLIISwe_sendMessage);
}

void Heavy_EP_MK1::cVar_OyUmAZI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wRpWrKWi, HV_BINOP_LESS_THAN, 1, m, &cBinop_wRpWrKWi_sendMessage);
}

void Heavy_EP_MK1::cIf_YXo0WfYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_SvNxgwyv, 0, m, &cSlice_SvNxgwyv_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_84tpamIM, 0, m, &cSlice_84tpamIM_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZJq0sCI6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IT7p1guU_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7hJNNhYI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cIf_dw0Rb8md_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DCzwWFBE_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_vacnVbtY, 0, m, &cSlice_vacnVbtY_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_JP4mGNIp, 0, m, &cSlice_JP4mGNIp_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_todgcz4E_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WkdFLadT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S7DTAUvH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cPack_TGa9AOTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dw0Rb8md, 0, m, &cIf_dw0Rb8md_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_YXo0WfYq, 0, m, &cIf_YXo0WfYq_sendMessage);
}

void Heavy_EP_MK1::cVar_MfvQWInI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_EpXBdGxj_sendMessage);
}

void Heavy_EP_MK1::cSlice_SvNxgwyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_BYT033Zm, 2, m, &cPack_BYT033Zm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_84tpamIM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_A5VlRO2i_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_BYT033Zm, 1, m, &cPack_BYT033Zm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_bNgyqWRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_EpXBdGxj_sendMessage);
}

void Heavy_EP_MK1::cIf_30KS2vcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_dw0Rb8md, 1, m, &cIf_dw0Rb8md_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_L9vaHYGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fpmdvxdk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cVar_u5tBj8Lb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9NOLQx4h_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cTabread_zixFG9DX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_za7kZ0e3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iG3mZ9o0_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_iwN4zIii_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mpKBBGkD, 0, m, &cSlice_mpKBBGkD_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lw2om64Y_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_v6d4l04b_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_mpKBBGkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_zixFG9DX, 1, m, &cTabread_zixFG9DX_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_zixFG9DX, 1, m, &cTabread_zixFG9DX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_qZNKNNj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sFu4E3zK_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSystem_voLMvJtv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_wnEj2stC_sendMessage);
}

void Heavy_EP_MK1::cBinop_178ekfBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fTIYVYXR, HV_BINOP_MIN, 0, m, &cBinop_fTIYVYXR_sendMessage);
}

void Heavy_EP_MK1::cCast_v6d4l04b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_178ekfBO_sendMessage);
}

void Heavy_EP_MK1::cCast_lw2om64Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qZNKNNj4, 0, m, &cVar_qZNKNNj4_sendMessage);
}

void Heavy_EP_MK1::cBinop_fTIYVYXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_zixFG9DX, 0, m, &cTabread_zixFG9DX_sendMessage);
}

void Heavy_EP_MK1::cMsg_sFu4E3zK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_voLMvJtv_sendMessage);
}

void Heavy_EP_MK1::cBinop_wnEj2stC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fTIYVYXR, HV_BINOP_MIN, 1, m, &cBinop_fTIYVYXR_sendMessage);
}

void Heavy_EP_MK1::cTabread_r8YGsDv2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aU6TuZlp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_X1p3HUe3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6oxnYXEa_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_ZshqjpYa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_E3eGCS7T, 0, m, &cSlice_E3eGCS7T_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_p8ajT9ad_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bx7WNS9f_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_E3eGCS7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_r8YGsDv2, 1, m, &cTabread_r8YGsDv2_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_r8YGsDv2, 1, m, &cTabread_r8YGsDv2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_nqwB3gob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kDPZ8rkP_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSystem_dFJmqMg6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_lWgQPRpo_sendMessage);
}

void Heavy_EP_MK1::cBinop_QSHAKfTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RTJGzepK, HV_BINOP_MIN, 0, m, &cBinop_RTJGzepK_sendMessage);
}

void Heavy_EP_MK1::cCast_p8ajT9ad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nqwB3gob, 0, m, &cVar_nqwB3gob_sendMessage);
}

void Heavy_EP_MK1::cCast_bx7WNS9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QSHAKfTC_sendMessage);
}

void Heavy_EP_MK1::cBinop_RTJGzepK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_r8YGsDv2, 0, m, &cTabread_r8YGsDv2_sendMessage);
}

void Heavy_EP_MK1::cMsg_kDPZ8rkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dFJmqMg6_sendMessage);
}

void Heavy_EP_MK1::cBinop_lWgQPRpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RTJGzepK, HV_BINOP_MIN, 1, m, &cBinop_RTJGzepK_sendMessage);
}

void Heavy_EP_MK1::cTabwrite_AFpLtIy7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cSwitchcase_D2TZQizS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Xgq2sBvz, 0, m, &cSlice_Xgq2sBvz_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_AFpLtIy7, 0, m, &cTabwrite_AFpLtIy7_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_Xgq2sBvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_AFpLtIy7, 2, m, &cTabwrite_AFpLtIy7_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_AFpLtIy7, 2, m, &cTabwrite_AFpLtIy7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cTabread_wzHGlVxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BYT033Zm, 1, m, &cPack_BYT033Zm_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_fpmdvxdk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_uQMKeyli, 0, m, &cSlice_uQMKeyli_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QnJqLA1M_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LeSduyOi_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_uQMKeyli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_wzHGlVxe, 1, m, &cTabread_wzHGlVxe_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_wzHGlVxe, 1, m, &cTabread_wzHGlVxe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_6vM6OQsr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2Bhduzp4_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSystem_96tJg7pf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tZWF9Lfj_sendMessage);
}

void Heavy_EP_MK1::cBinop_kDYam45V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n6HPoGNU, HV_BINOP_MIN, 0, m, &cBinop_n6HPoGNU_sendMessage);
}

void Heavy_EP_MK1::cCast_QnJqLA1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6vM6OQsr, 0, m, &cVar_6vM6OQsr_sendMessage);
}

void Heavy_EP_MK1::cCast_LeSduyOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kDYam45V_sendMessage);
}

void Heavy_EP_MK1::cBinop_n6HPoGNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_wzHGlVxe, 0, m, &cTabread_wzHGlVxe_sendMessage);
}

void Heavy_EP_MK1::cMsg_2Bhduzp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_96tJg7pf_sendMessage);
}

void Heavy_EP_MK1::cBinop_tZWF9Lfj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n6HPoGNU, HV_BINOP_MIN, 1, m, &cBinop_n6HPoGNU_sendMessage);
}

void Heavy_EP_MK1::cTabwrite_7CqRGpzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cSwitchcase_A5VlRO2i_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fGAlwoVk, 0, m, &cSlice_fGAlwoVk_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_7CqRGpzh, 0, m, &cTabwrite_7CqRGpzh_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_fGAlwoVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_7CqRGpzh, 2, m, &cTabwrite_7CqRGpzh_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_7CqRGpzh, 2, m, &cTabwrite_7CqRGpzh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cTabwrite_f431WPJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cSwitchcase_rOMtzLKD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_oeypQYGk, 0, m, &cSlice_oeypQYGk_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_f431WPJL, 0, m, &cTabwrite_f431WPJL_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_oeypQYGk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_f431WPJL, 2, m, &cTabwrite_f431WPJL_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_f431WPJL, 2, m, &cTabwrite_f431WPJL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cTabwrite_b1zrUtiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cSwitchcase_9NOLQx4h_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4y3BMUCB, 0, m, &cSlice_4y3BMUCB_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_b1zrUtiJ, 0, m, &cTabwrite_b1zrUtiJ_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_4y3BMUCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_b1zrUtiJ, 2, m, &cTabwrite_b1zrUtiJ_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_b1zrUtiJ, 2, m, &cTabwrite_b1zrUtiJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cTabwrite_ZnyIyMwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cSwitchcase_TA35kVMw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ahe4Nl54, 0, m, &cSlice_ahe4Nl54_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_ZnyIyMwB, 0, m, &cTabwrite_ZnyIyMwB_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_ahe4Nl54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_ZnyIyMwB, 2, m, &cTabwrite_ZnyIyMwB_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_ZnyIyMwB, 2, m, &cTabwrite_ZnyIyMwB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_GiSxSddZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TA35kVMw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cTabwrite_rhy4zqC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cSwitchcase_kkjJLu6h_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jJFqUT5D, 0, m, &cSlice_jJFqUT5D_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_rhy4zqC2, 0, m, &cTabwrite_rhy4zqC2_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_jJFqUT5D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_rhy4zqC2, 2, m, &cTabwrite_rhy4zqC2_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_rhy4zqC2, 2, m, &cTabwrite_rhy4zqC2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_MitV4kWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AoKOrzvT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_a8KlujQB_sendMessage);
}

void Heavy_EP_MK1::cSlice_vacnVbtY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_BYT033Zm, 2, m, &cPack_BYT033Zm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_JP4mGNIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_D2TZQizS_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_BYT033Zm, 1, m, &cPack_BYT033Zm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_aVw41OwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0TCmOiUi, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_0TCmOiUi_sendMessage);
}

void Heavy_EP_MK1::cBinop_Bhr229Ht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1dEz7w9q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_03VH1lVz_sendMessage);
}

void Heavy_EP_MK1::cBinop_VHLIISwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eieiD2dS, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_eieiD2dS_sendMessage);
}

void Heavy_EP_MK1::cCast_MzF5Hl3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cCast_Rqdzzopc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XpmYbjT4, 1, m, &cVar_XpmYbjT4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iiualsly, 1, m, &cVar_iiualsly_sendMessage);
}

void Heavy_EP_MK1::cCast_pRnu6zXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_iwN4zIii_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_QKm7gW5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZshqjpYa_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cSend_yCYNWwSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_T5RYnxvy_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_za7kZ0e3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bhr229Ht, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_Bhr229Ht_sendMessage);
}

void Heavy_EP_MK1::cCast_iG3mZ9o0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_xavIp2th_sendMessage);
}

void Heavy_EP_MK1::cBinop_eieiD2dS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0cDBtrS9, 0, m, &cIf_0cDBtrS9_sendMessage);
}

void Heavy_EP_MK1::cBinop_xavIp2th_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eieiD2dS, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_eieiD2dS_sendMessage);
}

void Heavy_EP_MK1::cCast_1dEz7w9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lEtY4E6Y_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_03VH1lVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_DGMgtVll_sendMessage);
}

void Heavy_EP_MK1::cBinop_DGMgtVll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0cDBtrS9, 1, m, &cIf_0cDBtrS9_sendMessage);
}

void Heavy_EP_MK1::cSend_WSDDndNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xWrZfXcb_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSend_Zs9LdfGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_T5RYnxvy_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSend_rYRzeYO9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xWrZfXcb_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_dcDNxpDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Cctho0iq_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_HwYRa9lS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MitV4kWM, 0, m, &cVar_MitV4kWM_sendMessage);
}

void Heavy_EP_MK1::cCast_u85ozOpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OkVpRRSw, 0, m, &cVar_OkVpRRSw_sendMessage);
}

void Heavy_EP_MK1::cBinop_wRpWrKWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bhr229Ht, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_Bhr229Ht_sendMessage);
}

void Heavy_EP_MK1::cCast_X1p3HUe3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wRpWrKWi, HV_BINOP_LESS_THAN, 0, m, &cBinop_wRpWrKWi_sendMessage);
}

void Heavy_EP_MK1::cCast_aU6TuZlp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dx2ZQG4K, 1, m, &cVar_dx2ZQG4K_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OyUmAZI6, 1, m, &cVar_OyUmAZI6_sendMessage);
}

void Heavy_EP_MK1::cCast_6oxnYXEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VHLIISwe, HV_BINOP_LESS_THAN, 0, m, &cBinop_VHLIISwe_sendMessage);
}

void Heavy_EP_MK1::cCast_AoKOrzvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OyUmAZI6, 0, m, &cVar_OyUmAZI6_sendMessage);
}

void Heavy_EP_MK1::cCast_a8KlujQB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dx2ZQG4K, 0, m, &cVar_dx2ZQG4K_sendMessage);
}

void Heavy_EP_MK1::cSend_uyNAOhx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YSOymCGl_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_yyCIcfT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iiualsly, 0, m, &cVar_iiualsly_sendMessage);
}

void Heavy_EP_MK1::cCast_yVBkpDUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dx2ZQG4K, 0, m, &cVar_dx2ZQG4K_sendMessage);
}

void Heavy_EP_MK1::cCast_lzcrmloV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wHfZKWQu_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_wHfZKWQu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_uyNAOhx6_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_JgknPyfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_Lrct6HgO_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSend_Lrct6HgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UNQwjlFB_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_A5avvMDt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XpmYbjT4, 0, m, &cVar_XpmYbjT4_sendMessage);
}

void Heavy_EP_MK1::cCast_Xlp3vC4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JgknPyfS_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_IQbanAHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OyUmAZI6, 0, m, &cVar_OyUmAZI6_sendMessage);
}

void Heavy_EP_MK1::cMsg_Cctho0iq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_rYRzeYO9_sendMessage(_c, 0, m);
  cSend_Zs9LdfGr_sendMessage(_c, 0, m);
  cSend_x9mgTo5s_sendMessage(_c, 0, m);
  cSend_NmT9TuoN_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSend_x9mgTo5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UNQwjlFB_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSend_NmT9TuoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YSOymCGl_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_xqKm824T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_B3C8qnN1_sendMessage);
}

void Heavy_EP_MK1::cCast_E0zeqvEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YXo0WfYq, 1, m, &cIf_YXo0WfYq_sendMessage);
}

void Heavy_EP_MK1::cBinop_0TCmOiUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_30KS2vcA, 0, m, &cIf_30KS2vcA_sendMessage);
}

void Heavy_EP_MK1::cBinop_B3C8qnN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aVw41OwU, 0, m, &cVar_aVw41OwU_sendMessage);
}

void Heavy_EP_MK1::cMsg_5bcombzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_rOMtzLKD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_EhOUqbOE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_kkjJLu6h_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_UqYgiBZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L9vaHYGJ, 0, m, &cVar_L9vaHYGJ_sendMessage);
}

void Heavy_EP_MK1::cCast_QIOH6Z9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bNgyqWRz, 0, m, &cVar_bNgyqWRz_sendMessage);
}

void Heavy_EP_MK1::cCast_ck24J6RM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9drSmKTs_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_9drSmKTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_BYT033Zm, 2, m, &cPack_BYT033Zm_sendMessage);
}

void Heavy_EP_MK1::cCast_IT7p1guU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5bcombzG_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_ZJq0sCI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MfvQWInI, 0, m, &cVar_MfvQWInI_sendMessage);
}

void Heavy_EP_MK1::cCast_7hJNNhYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4IkDDX1c_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1wJ4poyP_sendMessage);
}

void Heavy_EP_MK1::cCast_4IkDDX1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7OrG8WzM_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_1wJ4poyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_u5tBj8Lb, 0, m, &cVar_u5tBj8Lb_sendMessage);
}

void Heavy_EP_MK1::cSend_7OrG8WzM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RehAy77I_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_Dp1wu1wH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VtoZ7BwK_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_7sCGNTzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GiSxSddZ, 0, m, &cVar_GiSxSddZ_sendMessage);
}

void Heavy_EP_MK1::cSend_VtoZ7BwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RehAy77I_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_DCzwWFBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ck24J6RM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UqYgiBZ0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QIOH6Z9s_sendMessage);
}

void Heavy_EP_MK1::cCast_WkdFLadT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EhOUqbOE_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_S7DTAUvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dp1wu1wH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7sCGNTzx_sendMessage);
}

void Heavy_EP_MK1::cCast_todgcz4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bNgyqWRz, 0, m, &cVar_bNgyqWRz_sendMessage);
}

void Heavy_EP_MK1::cCast_WmFpuX9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0TCmOiUi, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_0TCmOiUi_sendMessage);
}

void Heavy_EP_MK1::cCast_hpLxvQwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aVw41OwU, 0, m, &cVar_aVw41OwU_sendMessage);
}

void Heavy_EP_MK1::cSend_TNisPs3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_78vPaVrA_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_Qa8GSBYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t9FMWBot, 1, m, &cVar_t9FMWBot_sendMessage);
}

void Heavy_EP_MK1::cSend_Vp3RAYli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Yvc0SbVa_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_EpXBdGxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BYT033Zm, 0, m, &cPack_BYT033Zm_sendMessage);
}

void Heavy_EP_MK1::cBinop_60vLkGOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Qa8GSBYv_sendMessage);
  cSend_Vp3RAYli_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::hTable_zrjAPWjU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::hTable_jDLA3bj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::hTable_103Wn1Ed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cCast_GXrq5eSO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_W2qTdReU, 0, m, &cVar_W2qTdReU_sendMessage);
}

void Heavy_EP_MK1::cCast_gjG7vzxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_01i7Qlvj_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSend_14E5VKgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VHVO9aGV_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_01i7Qlvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 65535.0f);
  cSend_14E5VKgj_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_aRCf7ezT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_D4wcmJuh, 1, m, &cIf_D4wcmJuh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_b9e8k91q_sendMessage);
}

void Heavy_EP_MK1::cBinop_b9e8k91q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_c0zUMuUL, 1, m, &cIf_c0zUMuUL_sendMessage);
}

void Heavy_EP_MK1::cBinop_7AH6hATD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_TNisPs3g_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_2INuIXhx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_jxSH4lC7_sendMessage);
      cSwitchcase_lBGbwojA_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_rIS4wCWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_a1Yr3GlD, 0, m, &cDelay_a1Yr3GlD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_anivr1Px_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_omE6hhyU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HPFjicw6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zkHxLmhP_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_fT5BH6mJ, 0, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_EnIDOsdo, m);
}

void Heavy_EP_MK1::cBinop_Zzp7ey9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_qNNqg8fl_sendMessage);
}

void Heavy_EP_MK1::cBinop_qNNqg8fl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D4pAxZXo, HV_BINOP_POW, 1, m, &cBinop_D4pAxZXo_sendMessage);
  cMsg_h9kP8P4g_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_D4pAxZXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_anivr1Px_sendMessage);
}

void Heavy_EP_MK1::cMsg_h9kP8P4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_D4pAxZXo, HV_BINOP_POW, 0, m, &cBinop_D4pAxZXo_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_APJ4Rlvd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_FGVof3f3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_FGVof3f3_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_fChR2EMd, 1, m, &cDelay_fChR2EMd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3kbCJtC1_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_fChR2EMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fChR2EMd, m);
  cPack_onMessage(_c, &Context(_c)->cPack_5c1776aq, 0, m, &cPack_5c1776aq_sendMessage);
}

void Heavy_EP_MK1::cMsg_FGVof3f3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fChR2EMd, 0, m, &cDelay_fChR2EMd_sendMessage);
}

void Heavy_EP_MK1::cCast_3kbCJtC1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fChR2EMd, 0, m, &cDelay_fChR2EMd_sendMessage);
}

void Heavy_EP_MK1::cPack_5c1776aq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3wCqimft_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_uOTUFrWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_eS2Rovnu_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_2v2J5hCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_lvEgPbs3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_f7mZhooZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lV6bOwnK, HV_BINOP_MULTIPLY, 0, m, &cBinop_lV6bOwnK_sendMessage);
}

void Heavy_EP_MK1::cMsg_emXeKopE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8NzDluXu_sendMessage);
}

void Heavy_EP_MK1::cSystem_8NzDluXu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QnG0Lrhv_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_lV6bOwnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Di0BSSgC_sendMessage);
}

void Heavy_EP_MK1::cBinop_GbGYOiva_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lV6bOwnK, HV_BINOP_MULTIPLY, 1, m, &cBinop_lV6bOwnK_sendMessage);
}

void Heavy_EP_MK1::cMsg_QnG0Lrhv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_GbGYOiva_sendMessage);
}

void Heavy_EP_MK1::cBinop_Di0BSSgC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_oqPfrp1J_sendMessage);
}

void Heavy_EP_MK1::cBinop_oqPfrp1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_JmyVXmNs_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_RcnTHRuu, m);
}

void Heavy_EP_MK1::cBinop_JmyVXmNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WD7C8chd, m);
}

void Heavy_EP_MK1::cSwitchcase_vgABNAXO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_EADYdXGl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_EADYdXGl_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_1yRWlMR0, 1, m, &cDelay_1yRWlMR0_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6KCFIGwR_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_1yRWlMR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1yRWlMR0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_SwGJLASp, 0, m, &cPack_SwGJLASp_sendMessage);
}

void Heavy_EP_MK1::cMsg_EADYdXGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1yRWlMR0, 0, m, &cDelay_1yRWlMR0_sendMessage);
}

void Heavy_EP_MK1::cCast_6KCFIGwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1yRWlMR0, 0, m, &cDelay_1yRWlMR0_sendMessage);
}

void Heavy_EP_MK1::cPack_SwGJLASp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4VZAheL7_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_dtyI5XH4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_McFVZ0Ll_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_0n4vTued_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_iDRS34B2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_cuvWDrFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CgfALdqs, HV_BINOP_MULTIPLY, 0, m, &cBinop_CgfALdqs_sendMessage);
}

void Heavy_EP_MK1::cMsg_fxp86nbP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cUfQczTw_sendMessage);
}

void Heavy_EP_MK1::cSystem_cUfQczTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7SQCIKgW_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_CgfALdqs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_r5YmAXgy_sendMessage);
}

void Heavy_EP_MK1::cBinop_qjO6txa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CgfALdqs, HV_BINOP_MULTIPLY, 1, m, &cBinop_CgfALdqs_sendMessage);
}

void Heavy_EP_MK1::cMsg_7SQCIKgW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_qjO6txa1_sendMessage);
}

void Heavy_EP_MK1::cBinop_r5YmAXgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_4ZiErfzd_sendMessage);
}

void Heavy_EP_MK1::cBinop_4ZiErfzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_bEbE8c1Q_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vp8lIXCn, m);
}

void Heavy_EP_MK1::cBinop_bEbE8c1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MfT4ifW4, m);
}

void Heavy_EP_MK1::cSwitchcase_lvSweEZ0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XuiDQjrM, 0, m, &cSlice_XuiDQjrM_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jf2Ro2dy, 0, m, &cSlice_jf2Ro2dy_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_XuiDQjrM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Zzp7ey9u_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Zzp7ey9u_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_jf2Ro2dy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_C9qeifus_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_C9qeifus_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_apMcAOFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pbsGlW4B_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HbyyrDXM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xoZj2b3V_sendMessage);
}

void Heavy_EP_MK1::cBinop_C9qeifus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_cXPXdUfF_sendMessage);
}

void Heavy_EP_MK1::cBinop_cXPXdUfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JmxewGJv, HV_BINOP_POW, 1, m, &cBinop_JmxewGJv_sendMessage);
  cMsg_KqRClAmB_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_JmxewGJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_apMcAOFx_sendMessage);
}

void Heavy_EP_MK1::cMsg_KqRClAmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JmxewGJv, HV_BINOP_POW, 0, m, &cBinop_JmxewGJv_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_lO6w9D3S_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8BHMru9s_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_8BHMru9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2XjwilZg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VQOHYJNi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oj0DbcAj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_03MpBgyk_sendMessage);
  cSwitchcase_YWGVI436_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_fNVYmuRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KdI1vnAr_sendMessage);
}

void Heavy_EP_MK1::cSystem_KdI1vnAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qx7mJTO2, m);
}

void Heavy_EP_MK1::cMsg_FyHDrtsd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_h4d3tlmE_sendMessage);
}

void Heavy_EP_MK1::cSystem_h4d3tlmE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Jiw4Es3V, m);
}

void Heavy_EP_MK1::cDelay_a1Yr3GlD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_a1Yr3GlD, m);
  cPack_onMessage(_c, &Context(_c)->cPack_nY24jnaO, 0, m, &cPack_nY24jnaO_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_dtNJQ6K6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_bsPSOHBL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_bsPSOHBL_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_odpMaBGc, 1, m, &cDelay_odpMaBGc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6WA4eR2z_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_odpMaBGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_odpMaBGc, m);
  cMsg_z5sQN4qF_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_bsPSOHBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_odpMaBGc, 0, m, &cDelay_odpMaBGc_sendMessage);
}

void Heavy_EP_MK1::cCast_6WA4eR2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_odpMaBGc, 0, m, &cDelay_odpMaBGc_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_7cpVtmSE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_HMN6u30V_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_HMN6u30V_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_zIGcbWr6, 1, m, &cDelay_zIGcbWr6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z1AJRAYb_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_zIGcbWr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zIGcbWr6, m);
  cMsg_lTPANKWv_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_HMN6u30V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zIGcbWr6, 0, m, &cDelay_zIGcbWr6_sendMessage);
}

void Heavy_EP_MK1::cCast_z1AJRAYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zIGcbWr6, 0, m, &cDelay_zIGcbWr6_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_YWGVI436_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_i0g200qz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_i0g200qz_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_PYqe7fPW, 1, m, &cDelay_PYqe7fPW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gKnnfuMu_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_PYqe7fPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PYqe7fPW, m);
  cMsg_aHPfufNm_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_i0g200qz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_PYqe7fPW, 0, m, &cDelay_PYqe7fPW_sendMessage);
}

void Heavy_EP_MK1::cCast_gKnnfuMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PYqe7fPW, 0, m, &cDelay_PYqe7fPW_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_s1xwGczR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_2AEOqncp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_2AEOqncp_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_YTuA3aGI, 1, m, &cDelay_YTuA3aGI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LELHGy7h_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_YTuA3aGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YTuA3aGI, m);
  cMsg_lRds2qee_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_2AEOqncp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YTuA3aGI, 0, m, &cDelay_YTuA3aGI_sendMessage);
}

void Heavy_EP_MK1::cCast_LELHGy7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YTuA3aGI, 0, m, &cDelay_YTuA3aGI_sendMessage);
}

void Heavy_EP_MK1::cDelay_B0f8yaM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_B0f8yaM4, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_zDi7M02d_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_lBGbwojA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S9fNqTQF_sendMessage);
      break;
    }
    default: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_B0f8yaM4, 0, m, &cDelay_B0f8yaM4_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_S9fNqTQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cIf_drS0YQ1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_9gpPNaLn_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_Cfh8L2Oh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cMsg_3GE6O36z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NbhbI6Aw, HV_BINOP_POW, 0, m, &cBinop_NbhbI6Aw_sendMessage);
}

void Heavy_EP_MK1::cBinop_NbhbI6Aw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3qDPWnPQ, m);
}

void Heavy_EP_MK1::cBinop_pOL4RXb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_f1GPe8wH_sendMessage);
}

void Heavy_EP_MK1::cCast_ALLoyhj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_drS0YQ1l, 0, m, &cIf_drS0YQ1l_sendMessage);
}

void Heavy_EP_MK1::cCast_nWnQKHDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_85xlG53a_sendMessage);
}

void Heavy_EP_MK1::cBinop_85xlG53a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_drS0YQ1l, 1, m, &cIf_drS0YQ1l_sendMessage);
}

void Heavy_EP_MK1::cBinop_Cfh8L2Oh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_pOL4RXb6_sendMessage);
}

void Heavy_EP_MK1::cMsg_9gpPNaLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3qDPWnPQ, m);
}

void Heavy_EP_MK1::cBinop_f1GPe8wH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NbhbI6Aw, HV_BINOP_POW, 1, m, &cBinop_NbhbI6Aw_sendMessage);
  cMsg_3GE6O36z_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cPack_nY24jnaO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AToUhGDl_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_jxSH4lC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lO6w9D3S_onMessage(_c, NULL, 0, m, NULL);
  cPack_onMessage(_c, &Context(_c)->cPack_nY24jnaO, 1, m, &cPack_nY24jnaO_sendMessage);
}

void Heavy_EP_MK1::cMsg_Kr66zLqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_C0Wn6bJr_sendMessage);
}

void Heavy_EP_MK1::cBinop_C0Wn6bJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R6mPsfGd, HV_BINOP_MULTIPLY, 0, m, &cBinop_R6mPsfGd_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_moMtXn4m_sendMessage);
}

void Heavy_EP_MK1::cCast_8LglT0zT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cs02sYyb_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_vSwCGGuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_APJ4Rlvd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_3wCqimft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uOTUFrWe, 0, m, &cSlice_uOTUFrWe_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_2v2J5hCG, 0, m, &cSlice_2v2J5hCG_sendMessage);
}

void Heavy_EP_MK1::cMsg_eS2Rovnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rRe2nMN0_sendMessage);
}

void Heavy_EP_MK1::cBinop_rRe2nMN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f7mZhooZ, 0, m, &cVar_f7mZhooZ_sendMessage);
}

void Heavy_EP_MK1::cMsg_aHPfufNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_fT5BH6mJ, 1, m);
}

void Heavy_EP_MK1::cBinop_R6mPsfGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5c1776aq, 1, m, &cPack_5c1776aq_sendMessage);
}

void Heavy_EP_MK1::cCast_VQOHYJNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2pZV6Isa_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_2XjwilZg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_7cpVtmSE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_2pZV6Isa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_hADdbIyX, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_lTPANKWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_hADdbIyX, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_qDV0Ytnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V4moeuRd_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_uZLgjKs3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vgABNAXO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_4VZAheL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_dtyI5XH4, 0, m, &cSlice_dtyI5XH4_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_0n4vTued, 0, m, &cSlice_0n4vTued_sendMessage);
}

void Heavy_EP_MK1::cMsg_McFVZ0Ll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_kIOWepAR_sendMessage);
}

void Heavy_EP_MK1::cBinop_kIOWepAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cuvWDrFY, 0, m, &cVar_cuvWDrFY_sendMessage);
}

void Heavy_EP_MK1::cMsg_V4moeuRd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_dtyI5XH4, 0, m, &cSlice_dtyI5XH4_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_0n4vTued, 0, m, &cSlice_0n4vTued_sendMessage);
}

void Heavy_EP_MK1::cBinop_moMtXn4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SwGJLASp, 1, m, &cPack_SwGJLASp_sendMessage);
}

void Heavy_EP_MK1::cMsg_HemNUF3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 50.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_dtyI5XH4, 0, m, &cSlice_dtyI5XH4_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_0n4vTued, 0, m, &cSlice_0n4vTued_sendMessage);
}

void Heavy_EP_MK1::cCast_pbsGlW4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0QFSYRTy_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_HbyyrDXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Kr66zLqC_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_xoZj2b3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5c1776aq, 0, m, &cPack_5c1776aq_sendMessage);
}

void Heavy_EP_MK1::cCast_HPFjicw6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Kr66zLqC_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_omE6hhyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NE37oH26_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_zkHxLmhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8LglT0zT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vSwCGGuH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qDV0Ytnx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uZLgjKs3_sendMessage);
}

void Heavy_EP_MK1::cMsg_NE37oH26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2048.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R6mPsfGd, HV_BINOP_MULTIPLY, 1, m, &cBinop_R6mPsfGd_sendMessage);
}

void Heavy_EP_MK1::cCast_oj0DbcAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_s1xwGczR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_03MpBgyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dtNJQ6K6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_lRds2qee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_QOlaVO7i, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_z5sQN4qF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20000.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_QOlaVO7i, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_cs02sYyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.1f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uOTUFrWe, 0, m, &cSlice_uOTUFrWe_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_2v2J5hCG, 0, m, &cSlice_2v2J5hCG_sendMessage);
}

void Heavy_EP_MK1::cBinop_zDi7M02d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 126.0f, 0, m, &cBinop_k49e22Gp_sendMessage);
}

void Heavy_EP_MK1::cBinop_k49e22Gp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R48tlqs4_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_R48tlqs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_NixFIDVe_sendMessage);
}

void Heavy_EP_MK1::cBinop_NixFIDVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -30.0f, 0, m, &cBinop_zrBIyQso_sendMessage);
}

void Heavy_EP_MK1::cBinop_zrBIyQso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_dhr9C5zZ_sendMessage);
}

void Heavy_EP_MK1::cBinop_dhr9C5zZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nWnQKHDf_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ALLoyhj4_sendMessage);
}

void Heavy_EP_MK1::cMsg_0QFSYRTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 8.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R6mPsfGd, HV_BINOP_MULTIPLY, 1, m, &cBinop_R6mPsfGd_sendMessage);
}

void Heavy_EP_MK1::cMsg_AToUhGDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_lvSweEZ0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cSlice_qZT4eBYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_jSR9zS7N_sendMessage);
      cSwitchcase_A3E6anWI_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_7oNej4sG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_QLMdRIRC, 0, m, &cDelay_QLMdRIRC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_l3RXDCtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X8ntNJtD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0TVO4cyV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VznD72iG_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_4cjQsVOb, 0, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_e5DnsKGN, m);
}

void Heavy_EP_MK1::cBinop_tsESU4RN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_nWXpuFVx_sendMessage);
}

void Heavy_EP_MK1::cBinop_nWXpuFVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AUKqDMCP, HV_BINOP_POW, 1, m, &cBinop_AUKqDMCP_sendMessage);
  cMsg_tuBmcMzI_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_AUKqDMCP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_l3RXDCtN_sendMessage);
}

void Heavy_EP_MK1::cMsg_tuBmcMzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AUKqDMCP, HV_BINOP_POW, 0, m, &cBinop_AUKqDMCP_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_pgCsBXVe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_kk9ldTid_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_kk9ldTid_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ZtwXRUif, 1, m, &cDelay_ZtwXRUif_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L5lS74o2_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_ZtwXRUif_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZtwXRUif, m);
  cPack_onMessage(_c, &Context(_c)->cPack_J0CLxFll, 0, m, &cPack_J0CLxFll_sendMessage);
}

void Heavy_EP_MK1::cMsg_kk9ldTid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZtwXRUif, 0, m, &cDelay_ZtwXRUif_sendMessage);
}

void Heavy_EP_MK1::cCast_L5lS74o2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZtwXRUif, 0, m, &cDelay_ZtwXRUif_sendMessage);
}

void Heavy_EP_MK1::cPack_J0CLxFll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_373QxMWp_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_YosQUGW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_z9hpzokD_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_w1ytFFHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_1ozkl1Ar, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_I5axLBa7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8mUuoz38, HV_BINOP_MULTIPLY, 0, m, &cBinop_8mUuoz38_sendMessage);
}

void Heavy_EP_MK1::cMsg_xUIk35fz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dhp6hY1K_sendMessage);
}

void Heavy_EP_MK1::cSystem_dhp6hY1K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_punPVQER_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_8mUuoz38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_bjbPNxTO_sendMessage);
}

void Heavy_EP_MK1::cBinop_llPN8wky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8mUuoz38, HV_BINOP_MULTIPLY, 1, m, &cBinop_8mUuoz38_sendMessage);
}

void Heavy_EP_MK1::cMsg_punPVQER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_llPN8wky_sendMessage);
}

void Heavy_EP_MK1::cBinop_bjbPNxTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_nCoZaBF0_sendMessage);
}

void Heavy_EP_MK1::cBinop_nCoZaBF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_9Mvq2M0P_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_oj8tkGiB, m);
}

void Heavy_EP_MK1::cBinop_9Mvq2M0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sChqoevv, m);
}

void Heavy_EP_MK1::cSwitchcase_y8kaEfcl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_sbFXwqUJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_sbFXwqUJ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_iN9nDqKH, 1, m, &cDelay_iN9nDqKH_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LaYbGFDV_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_iN9nDqKH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iN9nDqKH, m);
  cPack_onMessage(_c, &Context(_c)->cPack_XcUCeI3v, 0, m, &cPack_XcUCeI3v_sendMessage);
}

void Heavy_EP_MK1::cMsg_sbFXwqUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_iN9nDqKH, 0, m, &cDelay_iN9nDqKH_sendMessage);
}

void Heavy_EP_MK1::cCast_LaYbGFDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iN9nDqKH, 0, m, &cDelay_iN9nDqKH_sendMessage);
}

void Heavy_EP_MK1::cPack_XcUCeI3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uoSqrOtK_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_nOSjeXgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_azNXhhOX_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_qIBpEnnd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_zeHbGhXt, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_6lY50lnm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KyQEhWTY, HV_BINOP_MULTIPLY, 0, m, &cBinop_KyQEhWTY_sendMessage);
}

void Heavy_EP_MK1::cMsg_Axz1orYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mBQ668Zx_sendMessage);
}

void Heavy_EP_MK1::cSystem_mBQ668Zx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kVyfvXw5_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_KyQEhWTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WTmBkKQT_sendMessage);
}

void Heavy_EP_MK1::cBinop_tLvLAlZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KyQEhWTY, HV_BINOP_MULTIPLY, 1, m, &cBinop_KyQEhWTY_sendMessage);
}

void Heavy_EP_MK1::cMsg_kVyfvXw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tLvLAlZL_sendMessage);
}

void Heavy_EP_MK1::cBinop_WTmBkKQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jj4NG7qf_sendMessage);
}

void Heavy_EP_MK1::cBinop_jj4NG7qf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_FGtkRlDO_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WSO3zyqT, m);
}

void Heavy_EP_MK1::cBinop_FGtkRlDO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_r2nB2y1m, m);
}

void Heavy_EP_MK1::cSwitchcase_pqtCDn8K_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UaT8lPaC, 0, m, &cSlice_UaT8lPaC_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_F4UGzXJD, 0, m, &cSlice_F4UGzXJD_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_UaT8lPaC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_tsESU4RN_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_tsESU4RN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_F4UGzXJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_fJLC2pkO_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_fJLC2pkO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_QrSnCJCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IHqc9FA0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RYsIbmpD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QPhwkePi_sendMessage);
}

void Heavy_EP_MK1::cBinop_fJLC2pkO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_Fa78vtHE_sendMessage);
}

void Heavy_EP_MK1::cBinop_Fa78vtHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pNB7bAH5, HV_BINOP_POW, 1, m, &cBinop_pNB7bAH5_sendMessage);
  cMsg_ACimLjhV_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_pNB7bAH5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_QrSnCJCJ_sendMessage);
}

void Heavy_EP_MK1::cMsg_ACimLjhV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pNB7bAH5, HV_BINOP_POW, 0, m, &cBinop_pNB7bAH5_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_9ymEkSqF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aJfuyvxQ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_aJfuyvxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K43UmDls_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1ohY0MTH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dqXZ16ly_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_E9eETroy_sendMessage);
  cSwitchcase_cL0RKMBM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_vnInM2TA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qTrmIzZM_sendMessage);
}

void Heavy_EP_MK1::cSystem_qTrmIzZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ruyibc4Y, m);
}

void Heavy_EP_MK1::cMsg_zX4gvtjh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4b4CSsPS_sendMessage);
}

void Heavy_EP_MK1::cSystem_4b4CSsPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zp8XrZmD, m);
}

void Heavy_EP_MK1::cDelay_QLMdRIRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QLMdRIRC, m);
  cPack_onMessage(_c, &Context(_c)->cPack_X3O3xvTy, 0, m, &cPack_X3O3xvTy_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_xQdp3YLI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_R8N3OM8Z_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_R8N3OM8Z_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Jj5JoN3X, 1, m, &cDelay_Jj5JoN3X_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P2zWlT8E_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_Jj5JoN3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Jj5JoN3X, m);
  cMsg_3D0wbw8W_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_R8N3OM8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Jj5JoN3X, 0, m, &cDelay_Jj5JoN3X_sendMessage);
}

void Heavy_EP_MK1::cCast_P2zWlT8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Jj5JoN3X, 0, m, &cDelay_Jj5JoN3X_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_vt3e34wU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_v9CBBqPn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_v9CBBqPn_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_MT2IRF44, 1, m, &cDelay_MT2IRF44_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xQqze1C3_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_MT2IRF44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MT2IRF44, m);
  cMsg_OA7ujY6d_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_v9CBBqPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_MT2IRF44, 0, m, &cDelay_MT2IRF44_sendMessage);
}

void Heavy_EP_MK1::cCast_xQqze1C3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MT2IRF44, 0, m, &cDelay_MT2IRF44_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_cL0RKMBM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_XHPdcOXe_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_XHPdcOXe_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_kVeglpYz, 1, m, &cDelay_kVeglpYz_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PfH7zRUo_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_kVeglpYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kVeglpYz, m);
  cMsg_Q4J8dJu7_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_XHPdcOXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kVeglpYz, 0, m, &cDelay_kVeglpYz_sendMessage);
}

void Heavy_EP_MK1::cCast_PfH7zRUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kVeglpYz, 0, m, &cDelay_kVeglpYz_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_jGfys04F_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Gwj9Okrj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Gwj9Okrj_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_HjgtvZoF, 1, m, &cDelay_HjgtvZoF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DugDo7U9_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_HjgtvZoF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HjgtvZoF, m);
  cMsg_E21vn4iz_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_Gwj9Okrj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HjgtvZoF, 0, m, &cDelay_HjgtvZoF_sendMessage);
}

void Heavy_EP_MK1::cCast_DugDo7U9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HjgtvZoF, 0, m, &cDelay_HjgtvZoF_sendMessage);
}

void Heavy_EP_MK1::cDelay_AQqKKBe7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AQqKKBe7, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_RDIdQCKh_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_A3E6anWI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H1Xyhida_sendMessage);
      break;
    }
    default: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_AQqKKBe7, 0, m, &cDelay_AQqKKBe7_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_H1Xyhida_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cIf_riRtEjEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_VRC3oFCN_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_5r1OUzKN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cMsg_Dv0gbeDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kWGjKN5n, HV_BINOP_POW, 0, m, &cBinop_kWGjKN5n_sendMessage);
}

void Heavy_EP_MK1::cBinop_kWGjKN5n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NOYgXabI, m);
}

void Heavy_EP_MK1::cBinop_f5IHXl58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_cyjUUiEB_sendMessage);
}

void Heavy_EP_MK1::cCast_GnZxXwEh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_4fYWpMjF_sendMessage);
}

void Heavy_EP_MK1::cCast_XtWPeINd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_riRtEjEO, 0, m, &cIf_riRtEjEO_sendMessage);
}

void Heavy_EP_MK1::cBinop_4fYWpMjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_riRtEjEO, 1, m, &cIf_riRtEjEO_sendMessage);
}

void Heavy_EP_MK1::cBinop_5r1OUzKN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_f5IHXl58_sendMessage);
}

void Heavy_EP_MK1::cMsg_VRC3oFCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NOYgXabI, m);
}

void Heavy_EP_MK1::cBinop_cyjUUiEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kWGjKN5n, HV_BINOP_POW, 1, m, &cBinop_kWGjKN5n_sendMessage);
  cMsg_Dv0gbeDu_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cPack_X3O3xvTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1GrkztpU_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_jSR9zS7N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9ymEkSqF_onMessage(_c, NULL, 0, m, NULL);
  cPack_onMessage(_c, &Context(_c)->cPack_X3O3xvTy, 1, m, &cPack_X3O3xvTy_sendMessage);
}

void Heavy_EP_MK1::cMsg_UiZy1dIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_NavqPfVK_sendMessage);
}

void Heavy_EP_MK1::cBinop_NavqPfVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lyVu0twV, HV_BINOP_MULTIPLY, 0, m, &cBinop_lyVu0twV_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_aLAYvppH_sendMessage);
}

void Heavy_EP_MK1::cCast_9RZmugqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pgCsBXVe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_4s3ICg4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8FLxmPX4_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_373QxMWp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_YosQUGW6, 0, m, &cSlice_YosQUGW6_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_w1ytFFHJ, 0, m, &cSlice_w1ytFFHJ_sendMessage);
}

void Heavy_EP_MK1::cMsg_z9hpzokD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YopcEX5F_sendMessage);
}

void Heavy_EP_MK1::cBinop_YopcEX5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I5axLBa7, 0, m, &cVar_I5axLBa7_sendMessage);
}

void Heavy_EP_MK1::cMsg_Q4J8dJu7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_4cjQsVOb, 1, m);
}

void Heavy_EP_MK1::cBinop_lyVu0twV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_J0CLxFll, 1, m, &cPack_J0CLxFll_sendMessage);
}

void Heavy_EP_MK1::cCast_1ohY0MTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LWirqX4o_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_K43UmDls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vt3e34wU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_LWirqX4o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_cIX3zJqu, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_OA7ujY6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_cIX3zJqu, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_6IqByR64_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_y8kaEfcl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_uYrKbzq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nMKiO5o0_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_uoSqrOtK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_nOSjeXgq, 0, m, &cSlice_nOSjeXgq_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qIBpEnnd, 0, m, &cSlice_qIBpEnnd_sendMessage);
}

void Heavy_EP_MK1::cMsg_azNXhhOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_7ecYajZQ_sendMessage);
}

void Heavy_EP_MK1::cBinop_7ecYajZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6lY50lnm, 0, m, &cVar_6lY50lnm_sendMessage);
}

void Heavy_EP_MK1::cMsg_nMKiO5o0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_nOSjeXgq, 0, m, &cSlice_nOSjeXgq_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qIBpEnnd, 0, m, &cSlice_qIBpEnnd_sendMessage);
}

void Heavy_EP_MK1::cBinop_aLAYvppH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XcUCeI3v, 1, m, &cPack_XcUCeI3v_sendMessage);
}

void Heavy_EP_MK1::cMsg_XEuGrYAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 50.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_nOSjeXgq, 0, m, &cSlice_nOSjeXgq_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qIBpEnnd, 0, m, &cSlice_qIBpEnnd_sendMessage);
}

void Heavy_EP_MK1::cCast_QPhwkePi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_J0CLxFll, 0, m, &cPack_J0CLxFll_sendMessage);
}

void Heavy_EP_MK1::cCast_IHqc9FA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l00PrmVY_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_RYsIbmpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UiZy1dIH_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_VznD72iG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4s3ICg4T_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9RZmugqL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uYrKbzq4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6IqByR64_sendMessage);
}

void Heavy_EP_MK1::cCast_0TVO4cyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UiZy1dIH_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_X8ntNJtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DpvC8iyV_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_DpvC8iyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2048.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lyVu0twV, HV_BINOP_MULTIPLY, 1, m, &cBinop_lyVu0twV_sendMessage);
}

void Heavy_EP_MK1::cCast_dqXZ16ly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jGfys04F_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_E9eETroy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xQdp3YLI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_E21vn4iz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_LhlRTRkY, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_3D0wbw8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20000.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_LhlRTRkY, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_8FLxmPX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.1f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_YosQUGW6, 0, m, &cSlice_YosQUGW6_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_w1ytFFHJ, 0, m, &cSlice_w1ytFFHJ_sendMessage);
}

void Heavy_EP_MK1::cBinop_RDIdQCKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 126.0f, 0, m, &cBinop_dbIjZ05s_sendMessage);
}

void Heavy_EP_MK1::cBinop_dbIjZ05s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mg7dkvqn_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_mg7dkvqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_OdnvGDMS_sendMessage);
}

void Heavy_EP_MK1::cBinop_OdnvGDMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -30.0f, 0, m, &cBinop_Doptl4KB_sendMessage);
}

void Heavy_EP_MK1::cBinop_Doptl4KB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_pF0VBlT7_sendMessage);
}

void Heavy_EP_MK1::cBinop_pF0VBlT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GnZxXwEh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XtWPeINd_sendMessage);
}

void Heavy_EP_MK1::cMsg_l00PrmVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 8.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lyVu0twV, HV_BINOP_MULTIPLY, 1, m, &cBinop_lyVu0twV_sendMessage);
}

void Heavy_EP_MK1::cMsg_1GrkztpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_pqtCDn8K_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cSlice_hv3mUgaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_7zgCesuw_sendMessage);
      cSwitchcase_FxIazoX8_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_XWrWDCcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_VB784pvz, 0, m, &cDelay_VB784pvz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_k1cslq56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dh3TAdGP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_C2nbcAxp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W6tBOTnb_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_D5sKYl8D, 0, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_4WWOmkn4, m);
}

void Heavy_EP_MK1::cBinop_mFn54KU0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_nkoqLCHg_sendMessage);
}

void Heavy_EP_MK1::cBinop_nkoqLCHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c0i1xbS9, HV_BINOP_POW, 1, m, &cBinop_c0i1xbS9_sendMessage);
  cMsg_vtdhWGdp_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_c0i1xbS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_k1cslq56_sendMessage);
}

void Heavy_EP_MK1::cMsg_vtdhWGdp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_c0i1xbS9, HV_BINOP_POW, 0, m, &cBinop_c0i1xbS9_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_OuZLBvL4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_BmsJaQFL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_BmsJaQFL_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_6qAkbHP4, 1, m, &cDelay_6qAkbHP4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5Oo1MqXa_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_6qAkbHP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6qAkbHP4, m);
  cPack_onMessage(_c, &Context(_c)->cPack_HKhQT7B9, 0, m, &cPack_HKhQT7B9_sendMessage);
}

void Heavy_EP_MK1::cMsg_BmsJaQFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6qAkbHP4, 0, m, &cDelay_6qAkbHP4_sendMessage);
}

void Heavy_EP_MK1::cCast_5Oo1MqXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6qAkbHP4, 0, m, &cDelay_6qAkbHP4_sendMessage);
}

void Heavy_EP_MK1::cPack_HKhQT7B9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z7tFHTdk_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_FwTqvMn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_fbZMtyOu_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_DcHse9W3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_kx1tzfa7, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_r5ixlHEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HqjECEs6, HV_BINOP_MULTIPLY, 0, m, &cBinop_HqjECEs6_sendMessage);
}

void Heavy_EP_MK1::cMsg_EZLaZJk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SMrHWdXB_sendMessage);
}

void Heavy_EP_MK1::cSystem_SMrHWdXB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pdB8k1j2_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_HqjECEs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zGb3Cnpa_sendMessage);
}

void Heavy_EP_MK1::cBinop_3kpJHHGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HqjECEs6, HV_BINOP_MULTIPLY, 1, m, &cBinop_HqjECEs6_sendMessage);
}

void Heavy_EP_MK1::cMsg_pdB8k1j2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_3kpJHHGx_sendMessage);
}

void Heavy_EP_MK1::cBinop_zGb3Cnpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gcPqtQGi_sendMessage);
}

void Heavy_EP_MK1::cBinop_gcPqtQGi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TzI3zrOK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7O0Uks8x, m);
}

void Heavy_EP_MK1::cBinop_TzI3zrOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DyUZzAkb, m);
}

void Heavy_EP_MK1::cSwitchcase_VZIwLCKY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_R6ucXJ9d_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_R6ucXJ9d_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_fsNbhAVw, 1, m, &cDelay_fsNbhAVw_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h1Kd5tf8_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_fsNbhAVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fsNbhAVw, m);
  cPack_onMessage(_c, &Context(_c)->cPack_8rASSedI, 0, m, &cPack_8rASSedI_sendMessage);
}

void Heavy_EP_MK1::cMsg_R6ucXJ9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fsNbhAVw, 0, m, &cDelay_fsNbhAVw_sendMessage);
}

void Heavy_EP_MK1::cCast_h1Kd5tf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fsNbhAVw, 0, m, &cDelay_fsNbhAVw_sendMessage);
}

void Heavy_EP_MK1::cPack_8rASSedI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qI4eBhFz_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_SQTrpvHR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_9gEcXN0Q_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_TEczJAdP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_nFQtbdVq, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_9G2w7qnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wtCPn2v7, HV_BINOP_MULTIPLY, 0, m, &cBinop_wtCPn2v7_sendMessage);
}

void Heavy_EP_MK1::cMsg_cGPaQMM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xxiMeu4W_sendMessage);
}

void Heavy_EP_MK1::cSystem_xxiMeu4W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EW0528j1_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_wtCPn2v7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WjxnTodE_sendMessage);
}

void Heavy_EP_MK1::cBinop_M3xbRzHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wtCPn2v7, HV_BINOP_MULTIPLY, 1, m, &cBinop_wtCPn2v7_sendMessage);
}

void Heavy_EP_MK1::cMsg_EW0528j1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_M3xbRzHZ_sendMessage);
}

void Heavy_EP_MK1::cBinop_WjxnTodE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2gqweucP_sendMessage);
}

void Heavy_EP_MK1::cBinop_2gqweucP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_CVrmPTW2_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8A33dqbR, m);
}

void Heavy_EP_MK1::cBinop_CVrmPTW2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_K4mxXcbU, m);
}

void Heavy_EP_MK1::cSwitchcase_7VmBeFDc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MO4iCVh1, 0, m, &cSlice_MO4iCVh1_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QuX5M4S2, 0, m, &cSlice_QuX5M4S2_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_MO4iCVh1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mFn54KU0_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mFn54KU0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_QuX5M4S2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_MGu6DZGz_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_MGu6DZGz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_VbNqWaoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tOlKdVU3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DuodSYz6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HUgTLaW8_sendMessage);
}

void Heavy_EP_MK1::cBinop_MGu6DZGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_hsln8cTe_sendMessage);
}

void Heavy_EP_MK1::cBinop_hsln8cTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YN6RyC3N, HV_BINOP_POW, 1, m, &cBinop_YN6RyC3N_sendMessage);
  cMsg_mxr67C8l_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_YN6RyC3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_VbNqWaoC_sendMessage);
}

void Heavy_EP_MK1::cMsg_mxr67C8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YN6RyC3N, HV_BINOP_POW, 0, m, &cBinop_YN6RyC3N_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_ImYmO42I_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_E6y5dwjY_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_E6y5dwjY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zQBVGHM3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0ZfNJd7D_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Zxo46jA0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kveJf1Sf_sendMessage);
  cSwitchcase_Y3RBjbcE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_lYOaGMwk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lKIgXgzR_sendMessage);
}

void Heavy_EP_MK1::cSystem_lKIgXgzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LGgQiJgX, m);
}

void Heavy_EP_MK1::cMsg_7KV6tt6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9J223NWs_sendMessage);
}

void Heavy_EP_MK1::cSystem_9J223NWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tfwRhNIy, m);
}

void Heavy_EP_MK1::cDelay_VB784pvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VB784pvz, m);
  cPack_onMessage(_c, &Context(_c)->cPack_ydX1v6ep, 0, m, &cPack_ydX1v6ep_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_ydBi8MSl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_RlSWCAcx_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_RlSWCAcx_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_BlyG4Dem, 1, m, &cDelay_BlyG4Dem_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_e3MU2AC0_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_BlyG4Dem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BlyG4Dem, m);
  cMsg_yNYaSFdF_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_RlSWCAcx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_BlyG4Dem, 0, m, &cDelay_BlyG4Dem_sendMessage);
}

void Heavy_EP_MK1::cCast_e3MU2AC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BlyG4Dem, 0, m, &cDelay_BlyG4Dem_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_1f79Z8tz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_VaYAOZMq_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_VaYAOZMq_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_lesker1N, 1, m, &cDelay_lesker1N_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ieiXglU5_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_lesker1N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lesker1N, m);
  cMsg_C0QJdxdQ_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_VaYAOZMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_lesker1N, 0, m, &cDelay_lesker1N_sendMessage);
}

void Heavy_EP_MK1::cCast_ieiXglU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lesker1N, 0, m, &cDelay_lesker1N_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_Y3RBjbcE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_pXFlrQ1U_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_pXFlrQ1U_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_xS27Dv4p, 1, m, &cDelay_xS27Dv4p_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nfzHets3_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_xS27Dv4p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xS27Dv4p, m);
  cMsg_fY1gA9w2_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_pXFlrQ1U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_xS27Dv4p, 0, m, &cDelay_xS27Dv4p_sendMessage);
}

void Heavy_EP_MK1::cCast_nfzHets3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xS27Dv4p, 0, m, &cDelay_xS27Dv4p_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_GWKDlTzw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_fmDFusag_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_fmDFusag_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_nlscGUxB, 1, m, &cDelay_nlscGUxB_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hwx0FeG8_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_nlscGUxB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nlscGUxB, m);
  cMsg_GPvBkq5J_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_fmDFusag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nlscGUxB, 0, m, &cDelay_nlscGUxB_sendMessage);
}

void Heavy_EP_MK1::cCast_Hwx0FeG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nlscGUxB, 0, m, &cDelay_nlscGUxB_sendMessage);
}

void Heavy_EP_MK1::cDelay_8o62CkX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8o62CkX0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_03KuiZFi_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_FxIazoX8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BW4KDBEE_sendMessage);
      break;
    }
    default: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_8o62CkX0, 0, m, &cDelay_8o62CkX0_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_BW4KDBEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cIf_eE0PJb50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_J7V6QIXZ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_3P1RBOib_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cMsg_HydQQl0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dlGEIEnH, HV_BINOP_POW, 0, m, &cBinop_dlGEIEnH_sendMessage);
}

void Heavy_EP_MK1::cBinop_dlGEIEnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gMuBQaiz, m);
}

void Heavy_EP_MK1::cBinop_JIbo3cDI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_qdM3r4g0_sendMessage);
}

void Heavy_EP_MK1::cCast_9YBnlLR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_pCXsFq1U_sendMessage);
}

void Heavy_EP_MK1::cCast_G02Qw2wI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eE0PJb50, 0, m, &cIf_eE0PJb50_sendMessage);
}

void Heavy_EP_MK1::cBinop_pCXsFq1U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eE0PJb50, 1, m, &cIf_eE0PJb50_sendMessage);
}

void Heavy_EP_MK1::cBinop_3P1RBOib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_JIbo3cDI_sendMessage);
}

void Heavy_EP_MK1::cMsg_J7V6QIXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gMuBQaiz, m);
}

void Heavy_EP_MK1::cBinop_qdM3r4g0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dlGEIEnH, HV_BINOP_POW, 1, m, &cBinop_dlGEIEnH_sendMessage);
  cMsg_HydQQl0s_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cPack_ydX1v6ep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QBtHS11y_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_7zgCesuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ImYmO42I_onMessage(_c, NULL, 0, m, NULL);
  cPack_onMessage(_c, &Context(_c)->cPack_ydX1v6ep, 1, m, &cPack_ydX1v6ep_sendMessage);
}

void Heavy_EP_MK1::cMsg_AjbwGNok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xCpzb0GP_sendMessage);
}

void Heavy_EP_MK1::cBinop_xCpzb0GP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_av6hA3La, HV_BINOP_MULTIPLY, 0, m, &cBinop_av6hA3La_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_E8SMKbju_sendMessage);
}

void Heavy_EP_MK1::cCast_ESX30QvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OuZLBvL4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_IkUEaZ1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f84WaAVS_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_z7tFHTdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_FwTqvMn2, 0, m, &cSlice_FwTqvMn2_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DcHse9W3, 0, m, &cSlice_DcHse9W3_sendMessage);
}

void Heavy_EP_MK1::cMsg_fbZMtyOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_6hJ2N7Mg_sendMessage);
}

void Heavy_EP_MK1::cBinop_6hJ2N7Mg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_r5ixlHEt, 0, m, &cVar_r5ixlHEt_sendMessage);
}

void Heavy_EP_MK1::cMsg_fY1gA9w2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_D5sKYl8D, 1, m);
}

void Heavy_EP_MK1::cBinop_av6hA3La_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HKhQT7B9, 1, m, &cPack_HKhQT7B9_sendMessage);
}

void Heavy_EP_MK1::cCast_zQBVGHM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1f79Z8tz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_0ZfNJd7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uwlYxoQz_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_uwlYxoQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0sWTZ5AU, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_C0QJdxdQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0sWTZ5AU, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_wUSD8D2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Cb6tqB6O_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_6BTUuGXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VZIwLCKY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_qI4eBhFz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SQTrpvHR, 0, m, &cSlice_SQTrpvHR_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_TEczJAdP, 0, m, &cSlice_TEczJAdP_sendMessage);
}

void Heavy_EP_MK1::cMsg_9gEcXN0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_doxG9FU3_sendMessage);
}

void Heavy_EP_MK1::cBinop_doxG9FU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9G2w7qnP, 0, m, &cVar_9G2w7qnP_sendMessage);
}

void Heavy_EP_MK1::cMsg_Cb6tqB6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SQTrpvHR, 0, m, &cSlice_SQTrpvHR_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_TEczJAdP, 0, m, &cSlice_TEczJAdP_sendMessage);
}

void Heavy_EP_MK1::cBinop_E8SMKbju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_8rASSedI, 1, m, &cPack_8rASSedI_sendMessage);
}

void Heavy_EP_MK1::cMsg_mQMFYsBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 50.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SQTrpvHR, 0, m, &cSlice_SQTrpvHR_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_TEczJAdP, 0, m, &cSlice_TEczJAdP_sendMessage);
}

void Heavy_EP_MK1::cCast_HUgTLaW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HKhQT7B9, 0, m, &cPack_HKhQT7B9_sendMessage);
}

void Heavy_EP_MK1::cCast_tOlKdVU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4c8BwGsk_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_DuodSYz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AjbwGNok_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_C2nbcAxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AjbwGNok_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_W6tBOTnb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IkUEaZ1v_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ESX30QvR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wUSD8D2p_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6BTUuGXc_sendMessage);
}

void Heavy_EP_MK1::cCast_dh3TAdGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u3kusKbw_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_u3kusKbw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2048.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_av6hA3La, HV_BINOP_MULTIPLY, 1, m, &cBinop_av6hA3La_sendMessage);
}

void Heavy_EP_MK1::cCast_kveJf1Sf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ydBi8MSl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_Zxo46jA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GWKDlTzw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_GPvBkq5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_RzEGSGrh, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_yNYaSFdF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20000.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_RzEGSGrh, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_f84WaAVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.1f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_FwTqvMn2, 0, m, &cSlice_FwTqvMn2_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DcHse9W3, 0, m, &cSlice_DcHse9W3_sendMessage);
}

void Heavy_EP_MK1::cBinop_03KuiZFi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 126.0f, 0, m, &cBinop_m6xlByYI_sendMessage);
}

void Heavy_EP_MK1::cBinop_m6xlByYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cymXe6mx_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_cymXe6mx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_1qw1bhOJ_sendMessage);
}

void Heavy_EP_MK1::cBinop_1qw1bhOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -30.0f, 0, m, &cBinop_PxyOdmoJ_sendMessage);
}

void Heavy_EP_MK1::cBinop_PxyOdmoJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_xVrj7M6A_sendMessage);
}

void Heavy_EP_MK1::cBinop_xVrj7M6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9YBnlLR5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_G02Qw2wI_sendMessage);
}

void Heavy_EP_MK1::cMsg_4c8BwGsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 8.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_av6hA3La, HV_BINOP_MULTIPLY, 1, m, &cBinop_av6hA3La_sendMessage);
}

void Heavy_EP_MK1::cMsg_QBtHS11y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_7VmBeFDc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cSlice_jBZVqRID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_TwOQys3E_sendMessage);
      cSwitchcase_wLEk9jUQ_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_ZxsAnMyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_ouiGSpqr, 0, m, &cDelay_ouiGSpqr_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_8D0zCOwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3wJNYSfn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_joBtXzWK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bKX7cNBW_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_EcWjv2sM, 0, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7P4pkLFI, m);
}

void Heavy_EP_MK1::cBinop_BFi55qXh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_a8Dmzxhi_sendMessage);
}

void Heavy_EP_MK1::cBinop_a8Dmzxhi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0zmZNoDQ, HV_BINOP_POW, 1, m, &cBinop_0zmZNoDQ_sendMessage);
  cMsg_BKXRP7SB_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_0zmZNoDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_8D0zCOwK_sendMessage);
}

void Heavy_EP_MK1::cMsg_BKXRP7SB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0zmZNoDQ, HV_BINOP_POW, 0, m, &cBinop_0zmZNoDQ_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_0tNZuopx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_b3dOoUE9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_b3dOoUE9_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_boef1Edm, 1, m, &cDelay_boef1Edm_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sQrbAz25_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_boef1Edm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_boef1Edm, m);
  cPack_onMessage(_c, &Context(_c)->cPack_PKdgj686, 0, m, &cPack_PKdgj686_sendMessage);
}

void Heavy_EP_MK1::cMsg_b3dOoUE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_boef1Edm, 0, m, &cDelay_boef1Edm_sendMessage);
}

void Heavy_EP_MK1::cCast_sQrbAz25_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_boef1Edm, 0, m, &cDelay_boef1Edm_sendMessage);
}

void Heavy_EP_MK1::cPack_PKdgj686_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mTgLwddF_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_ZYqqPMEU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_emIZO9r0_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_9r5FvGx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_4tw7syWZ, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_43FOqtBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sG7uKtCn, HV_BINOP_MULTIPLY, 0, m, &cBinop_sG7uKtCn_sendMessage);
}

void Heavy_EP_MK1::cMsg_0b6oTzRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TfDHTZTQ_sendMessage);
}

void Heavy_EP_MK1::cSystem_TfDHTZTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZPbTlDVC_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_sG7uKtCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_4484JP4i_sendMessage);
}

void Heavy_EP_MK1::cBinop_idtx5U4Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sG7uKtCn, HV_BINOP_MULTIPLY, 1, m, &cBinop_sG7uKtCn_sendMessage);
}

void Heavy_EP_MK1::cMsg_ZPbTlDVC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_idtx5U4Z_sendMessage);
}

void Heavy_EP_MK1::cBinop_4484JP4i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VS2moOM6_sendMessage);
}

void Heavy_EP_MK1::cBinop_VS2moOM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_uoPduPOh_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Q2qDb61i, m);
}

void Heavy_EP_MK1::cBinop_uoPduPOh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_P4bF2htA, m);
}

void Heavy_EP_MK1::cSwitchcase_dasMg2O8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_CFDXVYei_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_CFDXVYei_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_0g9RNRzd, 1, m, &cDelay_0g9RNRzd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_khXLU10O_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_0g9RNRzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0g9RNRzd, m);
  cPack_onMessage(_c, &Context(_c)->cPack_zvNQLNNm, 0, m, &cPack_zvNQLNNm_sendMessage);
}

void Heavy_EP_MK1::cMsg_CFDXVYei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_0g9RNRzd, 0, m, &cDelay_0g9RNRzd_sendMessage);
}

void Heavy_EP_MK1::cCast_khXLU10O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0g9RNRzd, 0, m, &cDelay_0g9RNRzd_sendMessage);
}

void Heavy_EP_MK1::cPack_zvNQLNNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dhWXbkCm_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_OT28k0wW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_zf9NWU2Y_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_dX9iIu2e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_Uj8v2gts, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_PQrhAZRa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oqqJ1Paq, HV_BINOP_MULTIPLY, 0, m, &cBinop_oqqJ1Paq_sendMessage);
}

void Heavy_EP_MK1::cMsg_pkFtiTnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LEccOHgH_sendMessage);
}

void Heavy_EP_MK1::cSystem_LEccOHgH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dhca3X8S_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_oqqJ1Paq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7hb1OHvN_sendMessage);
}

void Heavy_EP_MK1::cBinop_nbWNwOai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oqqJ1Paq, HV_BINOP_MULTIPLY, 1, m, &cBinop_oqqJ1Paq_sendMessage);
}

void Heavy_EP_MK1::cMsg_Dhca3X8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_nbWNwOai_sendMessage);
}

void Heavy_EP_MK1::cBinop_7hb1OHvN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gspRXxvt_sendMessage);
}

void Heavy_EP_MK1::cBinop_gspRXxvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Yp2K2bFn_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9lhwrhxA, m);
}

void Heavy_EP_MK1::cBinop_Yp2K2bFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Gzvbv7EO, m);
}

void Heavy_EP_MK1::cSwitchcase_HLr2sT4G_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_yX2gZFzd, 0, m, &cSlice_yX2gZFzd_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_WyVXq3I4, 0, m, &cSlice_WyVXq3I4_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_yX2gZFzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_BFi55qXh_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_BFi55qXh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_WyVXq3I4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_H0Q3gbjl_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_H0Q3gbjl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_qSBIWrss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z4yPnLuA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IGOP15ec_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j8PzT9ic_sendMessage);
}

void Heavy_EP_MK1::cBinop_H0Q3gbjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_UOds2bwZ_sendMessage);
}

void Heavy_EP_MK1::cBinop_UOds2bwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4gLdkR2v, HV_BINOP_POW, 1, m, &cBinop_4gLdkR2v_sendMessage);
  cMsg_LavURYtr_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_4gLdkR2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_qSBIWrss_sendMessage);
}

void Heavy_EP_MK1::cMsg_LavURYtr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4gLdkR2v, HV_BINOP_POW, 0, m, &cBinop_4gLdkR2v_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_CRShH4uR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MBcjL5vu_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_MBcjL5vu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rnEOSonc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K0gOKmNO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_C864gYhG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FxwX0WGF_sendMessage);
  cSwitchcase_YNEcloRv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_ug9sv1mV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OegaO66V_sendMessage);
}

void Heavy_EP_MK1::cSystem_OegaO66V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gG3oyfVr, m);
}

void Heavy_EP_MK1::cMsg_37gYBrZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_54HbbWEF_sendMessage);
}

void Heavy_EP_MK1::cSystem_54HbbWEF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LJPeQeRw, m);
}

void Heavy_EP_MK1::cDelay_ouiGSpqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ouiGSpqr, m);
  cPack_onMessage(_c, &Context(_c)->cPack_Q2kgvi4X, 0, m, &cPack_Q2kgvi4X_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_2pQzutyz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_7dURQOkB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_7dURQOkB_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_QwttMs34, 1, m, &cDelay_QwttMs34_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fiLSD1a8_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_QwttMs34_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QwttMs34, m);
  cMsg_9h8G172A_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_7dURQOkB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QwttMs34, 0, m, &cDelay_QwttMs34_sendMessage);
}

void Heavy_EP_MK1::cCast_fiLSD1a8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QwttMs34, 0, m, &cDelay_QwttMs34_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_1WQogOMx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_2mrdE5XU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_2mrdE5XU_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ynpjLAAq, 1, m, &cDelay_ynpjLAAq_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hfPWaCT9_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_ynpjLAAq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ynpjLAAq, m);
  cMsg_Hibi7sqo_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_2mrdE5XU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ynpjLAAq, 0, m, &cDelay_ynpjLAAq_sendMessage);
}

void Heavy_EP_MK1::cCast_hfPWaCT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ynpjLAAq, 0, m, &cDelay_ynpjLAAq_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_YNEcloRv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_0kE9k5nr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_0kE9k5nr_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_8zQ9g5kN, 1, m, &cDelay_8zQ9g5kN_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WFxvrVBl_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_8zQ9g5kN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8zQ9g5kN, m);
  cMsg_wSRNQSnT_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_0kE9k5nr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8zQ9g5kN, 0, m, &cDelay_8zQ9g5kN_sendMessage);
}

void Heavy_EP_MK1::cCast_WFxvrVBl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8zQ9g5kN, 0, m, &cDelay_8zQ9g5kN_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_iKdqEjv6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_CMzciL5O_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_CMzciL5O_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_S4kddO82, 1, m, &cDelay_S4kddO82_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eF1E20Al_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_S4kddO82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_S4kddO82, m);
  cMsg_WTUX3k30_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_CMzciL5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_S4kddO82, 0, m, &cDelay_S4kddO82_sendMessage);
}

void Heavy_EP_MK1::cCast_eF1E20Al_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_S4kddO82, 0, m, &cDelay_S4kddO82_sendMessage);
}

void Heavy_EP_MK1::cDelay_IMZb3bj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IMZb3bj3, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ahqchjeT_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_wLEk9jUQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qeF9BmG7_sendMessage);
      break;
    }
    default: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_IMZb3bj3, 0, m, &cDelay_IMZb3bj3_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_qeF9BmG7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cIf_ZTxZJeNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_WxyRATiB_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_93XUb6ci_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cMsg_Mypfyhhi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WofbqBHk, HV_BINOP_POW, 0, m, &cBinop_WofbqBHk_sendMessage);
}

void Heavy_EP_MK1::cBinop_WofbqBHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QndJgocL, m);
}

void Heavy_EP_MK1::cBinop_TBS1MzlW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_ByESvDhb_sendMessage);
}

void Heavy_EP_MK1::cCast_9yzE6rZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_H2yxUgdZ_sendMessage);
}

void Heavy_EP_MK1::cCast_KjmrJTfq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZTxZJeNg, 0, m, &cIf_ZTxZJeNg_sendMessage);
}

void Heavy_EP_MK1::cBinop_H2yxUgdZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZTxZJeNg, 1, m, &cIf_ZTxZJeNg_sendMessage);
}

void Heavy_EP_MK1::cBinop_93XUb6ci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_TBS1MzlW_sendMessage);
}

void Heavy_EP_MK1::cMsg_WxyRATiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_QndJgocL, m);
}

void Heavy_EP_MK1::cBinop_ByESvDhb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WofbqBHk, HV_BINOP_POW, 1, m, &cBinop_WofbqBHk_sendMessage);
  cMsg_Mypfyhhi_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cPack_Q2kgvi4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fEdoPEOS_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_TwOQys3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_CRShH4uR_onMessage(_c, NULL, 0, m, NULL);
  cPack_onMessage(_c, &Context(_c)->cPack_Q2kgvi4X, 1, m, &cPack_Q2kgvi4X_sendMessage);
}

void Heavy_EP_MK1::cMsg_KH2G7xkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xWe7L4zj_sendMessage);
}

void Heavy_EP_MK1::cBinop_xWe7L4zj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K7pbLD1Z, HV_BINOP_MULTIPLY, 0, m, &cBinop_K7pbLD1Z_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_8hrzCrt9_sendMessage);
}

void Heavy_EP_MK1::cCast_zcQvtdXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HK3wrSdz_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_jyic7ZqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0tNZuopx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_mTgLwddF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ZYqqPMEU, 0, m, &cSlice_ZYqqPMEU_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_9r5FvGx8, 0, m, &cSlice_9r5FvGx8_sendMessage);
}

void Heavy_EP_MK1::cMsg_emIZO9r0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Z6h5tmz3_sendMessage);
}

void Heavy_EP_MK1::cBinop_Z6h5tmz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_43FOqtBR, 0, m, &cVar_43FOqtBR_sendMessage);
}

void Heavy_EP_MK1::cMsg_wSRNQSnT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_EcWjv2sM, 1, m);
}

void Heavy_EP_MK1::cBinop_K7pbLD1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PKdgj686, 1, m, &cPack_PKdgj686_sendMessage);
}

void Heavy_EP_MK1::cCast_rnEOSonc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1WQogOMx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_K0gOKmNO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qUsjHa38_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_qUsjHa38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dkF12Ve6, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_Hibi7sqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dkF12Ve6, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_3knme7ox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dasMg2O8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_UqHlaIWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n6bwrVpU_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_dhWXbkCm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OT28k0wW, 0, m, &cSlice_OT28k0wW_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_dX9iIu2e, 0, m, &cSlice_dX9iIu2e_sendMessage);
}

void Heavy_EP_MK1::cMsg_zf9NWU2Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_OTHnCVRL_sendMessage);
}

void Heavy_EP_MK1::cBinop_OTHnCVRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PQrhAZRa, 0, m, &cVar_PQrhAZRa_sendMessage);
}

void Heavy_EP_MK1::cMsg_n6bwrVpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OT28k0wW, 0, m, &cSlice_OT28k0wW_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_dX9iIu2e, 0, m, &cSlice_dX9iIu2e_sendMessage);
}

void Heavy_EP_MK1::cBinop_8hrzCrt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zvNQLNNm, 1, m, &cPack_zvNQLNNm_sendMessage);
}

void Heavy_EP_MK1::cMsg_HXadA5UE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 50.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OT28k0wW, 0, m, &cSlice_OT28k0wW_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_dX9iIu2e, 0, m, &cSlice_dX9iIu2e_sendMessage);
}

void Heavy_EP_MK1::cCast_j8PzT9ic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PKdgj686, 0, m, &cPack_PKdgj686_sendMessage);
}

void Heavy_EP_MK1::cCast_Z4yPnLuA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rjuAtuSd_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_IGOP15ec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KH2G7xkh_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_3wJNYSfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v5xOJFu4_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_bKX7cNBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zcQvtdXn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jyic7ZqL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UqHlaIWS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3knme7ox_sendMessage);
}

void Heavy_EP_MK1::cCast_joBtXzWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KH2G7xkh_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_v5xOJFu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2048.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_K7pbLD1Z, HV_BINOP_MULTIPLY, 1, m, &cBinop_K7pbLD1Z_sendMessage);
}

void Heavy_EP_MK1::cCast_FxwX0WGF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2pQzutyz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_C864gYhG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_iKdqEjv6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_WTUX3k30_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_qf13Df9a, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_9h8G172A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20000.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_qf13Df9a, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_HK3wrSdz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.1f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ZYqqPMEU, 0, m, &cSlice_ZYqqPMEU_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_9r5FvGx8, 0, m, &cSlice_9r5FvGx8_sendMessage);
}

void Heavy_EP_MK1::cBinop_ahqchjeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 126.0f, 0, m, &cBinop_SS75KJNe_sendMessage);
}

void Heavy_EP_MK1::cBinop_SS75KJNe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fvqvkU8j_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_fvqvkU8j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_BpYFlK4l_sendMessage);
}

void Heavy_EP_MK1::cBinop_BpYFlK4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -30.0f, 0, m, &cBinop_YiTSNoeT_sendMessage);
}

void Heavy_EP_MK1::cBinop_YiTSNoeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_FueLORJu_sendMessage);
}

void Heavy_EP_MK1::cBinop_FueLORJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9yzE6rZl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KjmrJTfq_sendMessage);
}

void Heavy_EP_MK1::cMsg_rjuAtuSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 8.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_K7pbLD1Z, HV_BINOP_MULTIPLY, 1, m, &cBinop_K7pbLD1Z_sendMessage);
}

void Heavy_EP_MK1::cMsg_fEdoPEOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_HLr2sT4G_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cSlice_YdkTn2WL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_SeoxEpEW_sendMessage);
      cSwitchcase_KhWvkQGW_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_IDtSoCz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_FpA49BkW, 0, m, &cDelay_FpA49BkW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_MCRwxge6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fQhFLMED_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tqTUMqUi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZD7HSBiV_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_E5G3BDc3, 0, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_2VaBCHEQ, m);
}

void Heavy_EP_MK1::cBinop_yeO0TBWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_QFXcKD54_sendMessage);
}

void Heavy_EP_MK1::cBinop_QFXcKD54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uWnhLLWD, HV_BINOP_POW, 1, m, &cBinop_uWnhLLWD_sendMessage);
  cMsg_UvKpFABm_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_uWnhLLWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_MCRwxge6_sendMessage);
}

void Heavy_EP_MK1::cMsg_UvKpFABm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uWnhLLWD, HV_BINOP_POW, 0, m, &cBinop_uWnhLLWD_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_ezgzLcgn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_p9jyzeym_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_p9jyzeym_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_LNwKVA6h, 1, m, &cDelay_LNwKVA6h_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XvGm9o4Q_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_LNwKVA6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LNwKVA6h, m);
  cPack_onMessage(_c, &Context(_c)->cPack_TPCSHBXT, 0, m, &cPack_TPCSHBXT_sendMessage);
}

void Heavy_EP_MK1::cMsg_p9jyzeym_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LNwKVA6h, 0, m, &cDelay_LNwKVA6h_sendMessage);
}

void Heavy_EP_MK1::cCast_XvGm9o4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LNwKVA6h, 0, m, &cDelay_LNwKVA6h_sendMessage);
}

void Heavy_EP_MK1::cPack_TPCSHBXT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dEhJmgRF_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_uN0zKAiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_yP4v5nNM_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_gNyzsSj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_9dY6u1g9, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_mrGWo2hl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6kvx4MW1, HV_BINOP_MULTIPLY, 0, m, &cBinop_6kvx4MW1_sendMessage);
}

void Heavy_EP_MK1::cMsg_0KIBKjcE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WSf7WIv4_sendMessage);
}

void Heavy_EP_MK1::cSystem_WSf7WIv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JtowgWnI_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_6kvx4MW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_yF8yz2t1_sendMessage);
}

void Heavy_EP_MK1::cBinop_G67N2Obe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6kvx4MW1, HV_BINOP_MULTIPLY, 1, m, &cBinop_6kvx4MW1_sendMessage);
}

void Heavy_EP_MK1::cMsg_JtowgWnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_G67N2Obe_sendMessage);
}

void Heavy_EP_MK1::cBinop_yF8yz2t1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tAnpPZo8_sendMessage);
}

void Heavy_EP_MK1::cBinop_tAnpPZo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_SRfrcYXZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ya0UY0D5, m);
}

void Heavy_EP_MK1::cBinop_SRfrcYXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WdJqQKz5, m);
}

void Heavy_EP_MK1::cSwitchcase_UtrhqNBS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_4RKAbsEh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_4RKAbsEh_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_8ZZIXXPz, 1, m, &cDelay_8ZZIXXPz_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GWLDX8FC_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_8ZZIXXPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8ZZIXXPz, m);
  cPack_onMessage(_c, &Context(_c)->cPack_5500f4rS, 0, m, &cPack_5500f4rS_sendMessage);
}

void Heavy_EP_MK1::cMsg_4RKAbsEh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8ZZIXXPz, 0, m, &cDelay_8ZZIXXPz_sendMessage);
}

void Heavy_EP_MK1::cCast_GWLDX8FC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8ZZIXXPz, 0, m, &cDelay_8ZZIXXPz_sendMessage);
}

void Heavy_EP_MK1::cPack_5500f4rS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_epTObcqo_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_V7WIm3dA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_maDapn8d_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_NBtNQH70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_Tln43Iuf, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_2nrwCzMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_laWCPJWj, HV_BINOP_MULTIPLY, 0, m, &cBinop_laWCPJWj_sendMessage);
}

void Heavy_EP_MK1::cMsg_lBdzS1y9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PcD9gYPr_sendMessage);
}

void Heavy_EP_MK1::cSystem_PcD9gYPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6bndNwzZ_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_laWCPJWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_FxqAL3Iz_sendMessage);
}

void Heavy_EP_MK1::cBinop_XRHl9hCk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_laWCPJWj, HV_BINOP_MULTIPLY, 1, m, &cBinop_laWCPJWj_sendMessage);
}

void Heavy_EP_MK1::cMsg_6bndNwzZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XRHl9hCk_sendMessage);
}

void Heavy_EP_MK1::cBinop_FxqAL3Iz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_uRKPU5nd_sendMessage);
}

void Heavy_EP_MK1::cBinop_uRKPU5nd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_QCh9dt7w_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lbmQbBe1, m);
}

void Heavy_EP_MK1::cBinop_QCh9dt7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QJuMdqAL, m);
}

void Heavy_EP_MK1::cSwitchcase_KfKBNZ1L_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QjjpI8v1, 0, m, &cSlice_QjjpI8v1_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mq0IVuSG, 0, m, &cSlice_mq0IVuSG_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_QjjpI8v1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_yeO0TBWK_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_yeO0TBWK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_mq0IVuSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_KuuB7P1e_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_KuuB7P1e_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_6TnJ4LDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ri54zFOR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_seJyTUwT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_C70yAhkD_sendMessage);
}

void Heavy_EP_MK1::cBinop_KuuB7P1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_WcuevvmP_sendMessage);
}

void Heavy_EP_MK1::cBinop_WcuevvmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yktdhsb8, HV_BINOP_POW, 1, m, &cBinop_yktdhsb8_sendMessage);
  cMsg_ZKM96kn2_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_yktdhsb8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_6TnJ4LDS_sendMessage);
}

void Heavy_EP_MK1::cMsg_ZKM96kn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yktdhsb8, HV_BINOP_POW, 0, m, &cBinop_yktdhsb8_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_lLPhmlID_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zvQI1Kd2_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_zvQI1Kd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ARxFbiyZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0bQ3YrqF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0panBpL9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fvV9VMDq_sendMessage);
  cSwitchcase_pkwO6v0F_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_duSEFOQ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oxVnMnXG_sendMessage);
}

void Heavy_EP_MK1::cSystem_oxVnMnXG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bwlmwK6X, m);
}

void Heavy_EP_MK1::cMsg_OmjfJHO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LLUvzUDy_sendMessage);
}

void Heavy_EP_MK1::cSystem_LLUvzUDy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LY96DS0r, m);
}

void Heavy_EP_MK1::cDelay_FpA49BkW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FpA49BkW, m);
  cPack_onMessage(_c, &Context(_c)->cPack_IAED51KK, 0, m, &cPack_IAED51KK_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_bZfJUN9p_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_55yu4tIW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_55yu4tIW_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Ksc6L6s1, 1, m, &cDelay_Ksc6L6s1_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tFC7OPru_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_Ksc6L6s1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ksc6L6s1, m);
  cMsg_rY9qYCDT_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_55yu4tIW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ksc6L6s1, 0, m, &cDelay_Ksc6L6s1_sendMessage);
}

void Heavy_EP_MK1::cCast_tFC7OPru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ksc6L6s1, 0, m, &cDelay_Ksc6L6s1_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_JhOu3BlT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_6nW5oczT_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_6nW5oczT_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_HD4QVfFN, 1, m, &cDelay_HD4QVfFN_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c2rXE83Z_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_HD4QVfFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HD4QVfFN, m);
  cMsg_mvBWrNAc_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_6nW5oczT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HD4QVfFN, 0, m, &cDelay_HD4QVfFN_sendMessage);
}

void Heavy_EP_MK1::cCast_c2rXE83Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HD4QVfFN, 0, m, &cDelay_HD4QVfFN_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_pkwO6v0F_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_pKlDVOMZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_pKlDVOMZ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_kEuwEux7, 1, m, &cDelay_kEuwEux7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WhqT1RWV_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_kEuwEux7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kEuwEux7, m);
  cMsg_12eibmLg_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_pKlDVOMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kEuwEux7, 0, m, &cDelay_kEuwEux7_sendMessage);
}

void Heavy_EP_MK1::cCast_WhqT1RWV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kEuwEux7, 0, m, &cDelay_kEuwEux7_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_lv6hvuVN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_MYsZWUB0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_MYsZWUB0_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_v6eu2VXR, 1, m, &cDelay_v6eu2VXR_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q57F9a4k_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_v6eu2VXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_v6eu2VXR, m);
  cMsg_pbeOxslE_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_MYsZWUB0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_v6eu2VXR, 0, m, &cDelay_v6eu2VXR_sendMessage);
}

void Heavy_EP_MK1::cCast_q57F9a4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_v6eu2VXR, 0, m, &cDelay_v6eu2VXR_sendMessage);
}

void Heavy_EP_MK1::cDelay_kJiO8EHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kJiO8EHE, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_DujDieyG_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_KhWvkQGW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QzeuJzkP_sendMessage);
      break;
    }
    default: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_kJiO8EHE, 0, m, &cDelay_kJiO8EHE_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_QzeuJzkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cIf_CxGKJWrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KCdLhw9p_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_7R1BuOcK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cMsg_67CDvPpH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gRP0w6t1, HV_BINOP_POW, 0, m, &cBinop_gRP0w6t1_sendMessage);
}

void Heavy_EP_MK1::cBinop_gRP0w6t1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jkwvGNGq, m);
}

void Heavy_EP_MK1::cBinop_6957mrj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_guqgmXzk_sendMessage);
}

void Heavy_EP_MK1::cCast_PasVdEIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ygZpnClk_sendMessage);
}

void Heavy_EP_MK1::cCast_wuAUZWeX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CxGKJWrF, 0, m, &cIf_CxGKJWrF_sendMessage);
}

void Heavy_EP_MK1::cBinop_ygZpnClk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CxGKJWrF, 1, m, &cIf_CxGKJWrF_sendMessage);
}

void Heavy_EP_MK1::cBinop_7R1BuOcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_6957mrj0_sendMessage);
}

void Heavy_EP_MK1::cMsg_KCdLhw9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jkwvGNGq, m);
}

void Heavy_EP_MK1::cBinop_guqgmXzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gRP0w6t1, HV_BINOP_POW, 1, m, &cBinop_gRP0w6t1_sendMessage);
  cMsg_67CDvPpH_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cPack_IAED51KK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W8jdGFW5_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_SeoxEpEW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lLPhmlID_onMessage(_c, NULL, 0, m, NULL);
  cPack_onMessage(_c, &Context(_c)->cPack_IAED51KK, 1, m, &cPack_IAED51KK_sendMessage);
}

void Heavy_EP_MK1::cMsg_ESSsls21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_cqeoyNml_sendMessage);
}

void Heavy_EP_MK1::cBinop_cqeoyNml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4QbhXBqM, HV_BINOP_MULTIPLY, 0, m, &cBinop_4QbhXBqM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_0lbLqOnp_sendMessage);
}

void Heavy_EP_MK1::cCast_FuyajRsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ezgzLcgn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_LvJ2wEk3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U9KDZkV1_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_dEhJmgRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uN0zKAiB, 0, m, &cSlice_uN0zKAiB_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gNyzsSj0, 0, m, &cSlice_gNyzsSj0_sendMessage);
}

void Heavy_EP_MK1::cMsg_yP4v5nNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_j1bGLY45_sendMessage);
}

void Heavy_EP_MK1::cBinop_j1bGLY45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mrGWo2hl, 0, m, &cVar_mrGWo2hl_sendMessage);
}

void Heavy_EP_MK1::cMsg_12eibmLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_E5G3BDc3, 1, m);
}

void Heavy_EP_MK1::cBinop_4QbhXBqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_TPCSHBXT, 1, m, &cPack_TPCSHBXT_sendMessage);
}

void Heavy_EP_MK1::cCast_0bQ3YrqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pgQvI5cl_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_ARxFbiyZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JhOu3BlT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_pgQvI5cl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_7VShF34d, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_mvBWrNAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_7VShF34d, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_tAN8PWzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U1WUhvfv_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_qfXDYMic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_UtrhqNBS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_epTObcqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_V7WIm3dA, 0, m, &cSlice_V7WIm3dA_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NBtNQH70, 0, m, &cSlice_NBtNQH70_sendMessage);
}

void Heavy_EP_MK1::cMsg_maDapn8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_LxB78UXU_sendMessage);
}

void Heavy_EP_MK1::cBinop_LxB78UXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2nrwCzMG, 0, m, &cVar_2nrwCzMG_sendMessage);
}

void Heavy_EP_MK1::cMsg_U1WUhvfv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_V7WIm3dA, 0, m, &cSlice_V7WIm3dA_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NBtNQH70, 0, m, &cSlice_NBtNQH70_sendMessage);
}

void Heavy_EP_MK1::cBinop_0lbLqOnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5500f4rS, 1, m, &cPack_5500f4rS_sendMessage);
}

void Heavy_EP_MK1::cMsg_pCDxJ11J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 50.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_V7WIm3dA, 0, m, &cSlice_V7WIm3dA_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NBtNQH70, 0, m, &cSlice_NBtNQH70_sendMessage);
}

void Heavy_EP_MK1::cCast_C70yAhkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_TPCSHBXT, 0, m, &cPack_TPCSHBXT_sendMessage);
}

void Heavy_EP_MK1::cCast_ri54zFOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R67BfFZp_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_seJyTUwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ESSsls21_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_ZD7HSBiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LvJ2wEk3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FuyajRsH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tAN8PWzQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qfXDYMic_sendMessage);
}

void Heavy_EP_MK1::cCast_tqTUMqUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ESSsls21_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_fQhFLMED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_589toPCL_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_589toPCL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2048.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4QbhXBqM, HV_BINOP_MULTIPLY, 1, m, &cBinop_4QbhXBqM_sendMessage);
}

void Heavy_EP_MK1::cCast_0panBpL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lv6hvuVN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_fvV9VMDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bZfJUN9p_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_pbeOxslE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_cB6SyVDf, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_rY9qYCDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20000.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_cB6SyVDf, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_U9KDZkV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.1f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uN0zKAiB, 0, m, &cSlice_uN0zKAiB_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gNyzsSj0, 0, m, &cSlice_gNyzsSj0_sendMessage);
}

void Heavy_EP_MK1::cBinop_DujDieyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 126.0f, 0, m, &cBinop_uW0B7FY8_sendMessage);
}

void Heavy_EP_MK1::cBinop_uW0B7FY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pvvvyjWZ_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_pvvvyjWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_7grpLFXN_sendMessage);
}

void Heavy_EP_MK1::cBinop_7grpLFXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -30.0f, 0, m, &cBinop_aCHgNo2I_sendMessage);
}

void Heavy_EP_MK1::cBinop_aCHgNo2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_XRrhABpI_sendMessage);
}

void Heavy_EP_MK1::cBinop_XRrhABpI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PasVdEIu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wuAUZWeX_sendMessage);
}

void Heavy_EP_MK1::cMsg_R67BfFZp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 8.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4QbhXBqM, HV_BINOP_MULTIPLY, 1, m, &cBinop_4QbhXBqM_sendMessage);
}

void Heavy_EP_MK1::cMsg_W8jdGFW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_KfKBNZ1L_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cSlice_DP57ivEA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_LiMj0H1p_sendMessage);
      cSwitchcase_5yZ4bMmj_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_Jed3KeQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_Eru9gouJ, 0, m, &cDelay_Eru9gouJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_XWJ2Jqvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RxFf9vpl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kUVyFe3n_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KQQK3QFZ_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_c7vJg0xU, 0, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_wMKdFxWD, m);
}

void Heavy_EP_MK1::cBinop_1OXqZ6Bg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_L6DcXzbK_sendMessage);
}

void Heavy_EP_MK1::cBinop_L6DcXzbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nhMYm0st, HV_BINOP_POW, 1, m, &cBinop_nhMYm0st_sendMessage);
  cMsg_rNIiSd33_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_nhMYm0st_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_XWJ2Jqvu_sendMessage);
}

void Heavy_EP_MK1::cMsg_rNIiSd33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nhMYm0st, HV_BINOP_POW, 0, m, &cBinop_nhMYm0st_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_MLt0O8yg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_EiR4r4A2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_EiR4r4A2_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_n7LU68W4, 1, m, &cDelay_n7LU68W4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0UPpbu1i_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_n7LU68W4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_n7LU68W4, m);
  cPack_onMessage(_c, &Context(_c)->cPack_Ty4AZCCD, 0, m, &cPack_Ty4AZCCD_sendMessage);
}

void Heavy_EP_MK1::cMsg_EiR4r4A2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_n7LU68W4, 0, m, &cDelay_n7LU68W4_sendMessage);
}

void Heavy_EP_MK1::cCast_0UPpbu1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_n7LU68W4, 0, m, &cDelay_n7LU68W4_sendMessage);
}

void Heavy_EP_MK1::cPack_Ty4AZCCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y9otndkl_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_eySO46yn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_mOOlRxTK_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_KnxapYvS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_kZnFwfGv, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_JD9szZbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CATg6nPr, HV_BINOP_MULTIPLY, 0, m, &cBinop_CATg6nPr_sendMessage);
}

void Heavy_EP_MK1::cMsg_KXtXNOXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kBcjJvxp_sendMessage);
}

void Heavy_EP_MK1::cSystem_kBcjJvxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OPUlBkwh_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_CATg6nPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_4P51wQVc_sendMessage);
}

void Heavy_EP_MK1::cBinop_fXBy05cL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CATg6nPr, HV_BINOP_MULTIPLY, 1, m, &cBinop_CATg6nPr_sendMessage);
}

void Heavy_EP_MK1::cMsg_OPUlBkwh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_fXBy05cL_sendMessage);
}

void Heavy_EP_MK1::cBinop_4P51wQVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DZiVayHP_sendMessage);
}

void Heavy_EP_MK1::cBinop_DZiVayHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_21680sPq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1LU3jUnE, m);
}

void Heavy_EP_MK1::cBinop_21680sPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fNWQjrL4, m);
}

void Heavy_EP_MK1::cSwitchcase_SIDB48EI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_TJmmUm5U_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_TJmmUm5U_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_dEFDi52d, 1, m, &cDelay_dEFDi52d_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wPee7GS2_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_dEFDi52d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dEFDi52d, m);
  cPack_onMessage(_c, &Context(_c)->cPack_uFHXRF1N, 0, m, &cPack_uFHXRF1N_sendMessage);
}

void Heavy_EP_MK1::cMsg_TJmmUm5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_dEFDi52d, 0, m, &cDelay_dEFDi52d_sendMessage);
}

void Heavy_EP_MK1::cCast_wPee7GS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dEFDi52d, 0, m, &cDelay_dEFDi52d_sendMessage);
}

void Heavy_EP_MK1::cPack_uFHXRF1N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LNpaIlFU_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_ADmSntnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_hxFLOadH_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_S4L3afF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_uSJzSkBR, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_81HDz8CE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l8zt39cL, HV_BINOP_MULTIPLY, 0, m, &cBinop_l8zt39cL_sendMessage);
}

void Heavy_EP_MK1::cMsg_qRQ3L6AU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ihOT8CW7_sendMessage);
}

void Heavy_EP_MK1::cSystem_ihOT8CW7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0iV9pJKf_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_l8zt39cL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_IX3mHvPq_sendMessage);
}

void Heavy_EP_MK1::cBinop_7CG1MZIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l8zt39cL, HV_BINOP_MULTIPLY, 1, m, &cBinop_l8zt39cL_sendMessage);
}

void Heavy_EP_MK1::cMsg_0iV9pJKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_7CG1MZIg_sendMessage);
}

void Heavy_EP_MK1::cBinop_IX3mHvPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_qJXVtB2A_sendMessage);
}

void Heavy_EP_MK1::cBinop_qJXVtB2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_BNTxg7wx_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_H49aKc1Z, m);
}

void Heavy_EP_MK1::cBinop_BNTxg7wx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XOZLXNvW, m);
}

void Heavy_EP_MK1::cSwitchcase_FvgdxOkD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_K6SmtxqU, 0, m, &cSlice_K6SmtxqU_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BHreXGfs, 0, m, &cSlice_BHreXGfs_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_K6SmtxqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_1OXqZ6Bg_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_1OXqZ6Bg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_BHreXGfs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_zwbFLVjY_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_zwbFLVjY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_ky3Oc79Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tj0WiuA4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wEEN8feL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jsHkXYE2_sendMessage);
}

void Heavy_EP_MK1::cBinop_zwbFLVjY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_5Eah3OBE_sendMessage);
}

void Heavy_EP_MK1::cBinop_5Eah3OBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ajNW3u8W, HV_BINOP_POW, 1, m, &cBinop_ajNW3u8W_sendMessage);
  cMsg_OusnrNph_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_ajNW3u8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ky3Oc79Z_sendMessage);
}

void Heavy_EP_MK1::cMsg_OusnrNph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ajNW3u8W, HV_BINOP_POW, 0, m, &cBinop_ajNW3u8W_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_yHQBYmnf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wLxvsE6d_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_wLxvsE6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0pDnxeRd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YhfQGkQv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cXXTcBNa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2W3kMZr0_sendMessage);
  cSwitchcase_zPJOqjLQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_w9j1Cdjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wf9WYwuy_sendMessage);
}

void Heavy_EP_MK1::cSystem_wf9WYwuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tRrgHLef, m);
}

void Heavy_EP_MK1::cMsg_dHvyDREf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4tmfAejR_sendMessage);
}

void Heavy_EP_MK1::cSystem_4tmfAejR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jvcAXwqO, m);
}

void Heavy_EP_MK1::cDelay_Eru9gouJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Eru9gouJ, m);
  cPack_onMessage(_c, &Context(_c)->cPack_mmRiOoWd, 0, m, &cPack_mmRiOoWd_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_iphHSLaK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_rhxubJln_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_rhxubJln_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_md93CS7M, 1, m, &cDelay_md93CS7M_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6wIpt0f5_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_md93CS7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_md93CS7M, m);
  cMsg_q4ou76oU_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_rhxubJln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_md93CS7M, 0, m, &cDelay_md93CS7M_sendMessage);
}

void Heavy_EP_MK1::cCast_6wIpt0f5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_md93CS7M, 0, m, &cDelay_md93CS7M_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_Kbkd3R0N_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_oOiNLMaR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_oOiNLMaR_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_UvgBzaAj, 1, m, &cDelay_UvgBzaAj_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JDJQipxH_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_UvgBzaAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UvgBzaAj, m);
  cMsg_O9aaqDcW_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_oOiNLMaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_UvgBzaAj, 0, m, &cDelay_UvgBzaAj_sendMessage);
}

void Heavy_EP_MK1::cCast_JDJQipxH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UvgBzaAj, 0, m, &cDelay_UvgBzaAj_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_zPJOqjLQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_aLvxbWK8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_aLvxbWK8_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_M1nBpgGs, 1, m, &cDelay_M1nBpgGs_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xKZO3BGD_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_M1nBpgGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_M1nBpgGs, m);
  cMsg_pvqTzqZi_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_aLvxbWK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_M1nBpgGs, 0, m, &cDelay_M1nBpgGs_sendMessage);
}

void Heavy_EP_MK1::cCast_xKZO3BGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_M1nBpgGs, 0, m, &cDelay_M1nBpgGs_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_SP2hdOgO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_qLJXwPi3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_qLJXwPi3_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_9Ftkd6Fy, 1, m, &cDelay_9Ftkd6Fy_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5rZAbeSu_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_9Ftkd6Fy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9Ftkd6Fy, m);
  cMsg_emZ4AHDA_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_qLJXwPi3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9Ftkd6Fy, 0, m, &cDelay_9Ftkd6Fy_sendMessage);
}

void Heavy_EP_MK1::cCast_5rZAbeSu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9Ftkd6Fy, 0, m, &cDelay_9Ftkd6Fy_sendMessage);
}

void Heavy_EP_MK1::cDelay_8hDBcNPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8hDBcNPP, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nAVnFHzn_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_5yZ4bMmj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YEv4mvrq_sendMessage);
      break;
    }
    default: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_8hDBcNPP, 0, m, &cDelay_8hDBcNPP_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_YEv4mvrq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cIf_BPYXa7JB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_8VLFejsr_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_KARnIlLo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cMsg_mELWUgjr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2zKbOLUN, HV_BINOP_POW, 0, m, &cBinop_2zKbOLUN_sendMessage);
}

void Heavy_EP_MK1::cBinop_2zKbOLUN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OHtE4ZXn, m);
}

void Heavy_EP_MK1::cBinop_ZOs8DKQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_i9YyF27D_sendMessage);
}

void Heavy_EP_MK1::cCast_JCdLNV35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BPYXa7JB, 0, m, &cIf_BPYXa7JB_sendMessage);
}

void Heavy_EP_MK1::cCast_dzWVGIcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_KK4RoHV1_sendMessage);
}

void Heavy_EP_MK1::cBinop_KK4RoHV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BPYXa7JB, 1, m, &cIf_BPYXa7JB_sendMessage);
}

void Heavy_EP_MK1::cBinop_KARnIlLo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_ZOs8DKQs_sendMessage);
}

void Heavy_EP_MK1::cMsg_8VLFejsr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OHtE4ZXn, m);
}

void Heavy_EP_MK1::cBinop_i9YyF27D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2zKbOLUN, HV_BINOP_POW, 1, m, &cBinop_2zKbOLUN_sendMessage);
  cMsg_mELWUgjr_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cPack_mmRiOoWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1yChKnRB_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_LiMj0H1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_yHQBYmnf_onMessage(_c, NULL, 0, m, NULL);
  cPack_onMessage(_c, &Context(_c)->cPack_mmRiOoWd, 1, m, &cPack_mmRiOoWd_sendMessage);
}

void Heavy_EP_MK1::cMsg_PiRptExk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Iui2p1my_sendMessage);
}

void Heavy_EP_MK1::cBinop_Iui2p1my_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mrXlugiY, HV_BINOP_MULTIPLY, 0, m, &cBinop_mrXlugiY_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_1oVhcKAe_sendMessage);
}

void Heavy_EP_MK1::cCast_JfIIyAwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O5mrDaec_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_rIzOVftP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_MLt0O8yg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_y9otndkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_eySO46yn, 0, m, &cSlice_eySO46yn_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_KnxapYvS, 0, m, &cSlice_KnxapYvS_sendMessage);
}

void Heavy_EP_MK1::cMsg_mOOlRxTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_oVUrXZdH_sendMessage);
}

void Heavy_EP_MK1::cBinop_oVUrXZdH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JD9szZbV, 0, m, &cVar_JD9szZbV_sendMessage);
}

void Heavy_EP_MK1::cMsg_pvqTzqZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_c7vJg0xU, 1, m);
}

void Heavy_EP_MK1::cBinop_mrXlugiY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Ty4AZCCD, 1, m, &cPack_Ty4AZCCD_sendMessage);
}

void Heavy_EP_MK1::cCast_YhfQGkQv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qBcuZRgZ_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_0pDnxeRd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Kbkd3R0N_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_qBcuZRgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_j9bBmCVa, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_O9aaqDcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_j9bBmCVa, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_JctnXzZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SIDB48EI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_QtcmGkpO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DanocuFQ_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_LNpaIlFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ADmSntnx, 0, m, &cSlice_ADmSntnx_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_S4L3afF2, 0, m, &cSlice_S4L3afF2_sendMessage);
}

void Heavy_EP_MK1::cMsg_hxFLOadH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Q3fdZqnO_sendMessage);
}

void Heavy_EP_MK1::cBinop_Q3fdZqnO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_81HDz8CE, 0, m, &cVar_81HDz8CE_sendMessage);
}

void Heavy_EP_MK1::cMsg_DanocuFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ADmSntnx, 0, m, &cSlice_ADmSntnx_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_S4L3afF2, 0, m, &cSlice_S4L3afF2_sendMessage);
}

void Heavy_EP_MK1::cBinop_1oVhcKAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uFHXRF1N, 1, m, &cPack_uFHXRF1N_sendMessage);
}

void Heavy_EP_MK1::cMsg_etboRD1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 50.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ADmSntnx, 0, m, &cSlice_ADmSntnx_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_S4L3afF2, 0, m, &cSlice_S4L3afF2_sendMessage);
}

void Heavy_EP_MK1::cCast_wEEN8feL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PiRptExk_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_jsHkXYE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Ty4AZCCD, 0, m, &cPack_Ty4AZCCD_sendMessage);
}

void Heavy_EP_MK1::cCast_tj0WiuA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RZ0SPTOO_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_RxFf9vpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HMxya2xZ_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_KQQK3QFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JfIIyAwg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rIzOVftP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QtcmGkpO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JctnXzZ6_sendMessage);
}

void Heavy_EP_MK1::cCast_kUVyFe3n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PiRptExk_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_HMxya2xZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2048.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mrXlugiY, HV_BINOP_MULTIPLY, 1, m, &cBinop_mrXlugiY_sendMessage);
}

void Heavy_EP_MK1::cCast_cXXTcBNa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SP2hdOgO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_2W3kMZr0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_iphHSLaK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_emZ4AHDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_sg8Xev4V, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_q4ou76oU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20000.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_sg8Xev4V, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_O5mrDaec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.1f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_eySO46yn, 0, m, &cSlice_eySO46yn_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_KnxapYvS, 0, m, &cSlice_KnxapYvS_sendMessage);
}

void Heavy_EP_MK1::cBinop_nAVnFHzn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 126.0f, 0, m, &cBinop_x5YXpkez_sendMessage);
}

void Heavy_EP_MK1::cBinop_x5YXpkez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Rli0KmaV_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_Rli0KmaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_PoYID1D7_sendMessage);
}

void Heavy_EP_MK1::cBinop_PoYID1D7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -30.0f, 0, m, &cBinop_PXx3naOw_sendMessage);
}

void Heavy_EP_MK1::cBinop_PXx3naOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_pGk0g3cc_sendMessage);
}

void Heavy_EP_MK1::cBinop_pGk0g3cc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dzWVGIcK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JCdLNV35_sendMessage);
}

void Heavy_EP_MK1::cMsg_RZ0SPTOO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 8.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mrXlugiY, HV_BINOP_MULTIPLY, 1, m, &cBinop_mrXlugiY_sendMessage);
}

void Heavy_EP_MK1::cMsg_1yChKnRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_FvgdxOkD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cSlice_kpwhR0tf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Lo45ltl1_sendMessage);
      cSwitchcase_4bJ7vNfF_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_oh4auhT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_3FZn93hs, 0, m, &cDelay_3FZn93hs_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_9GkGoUNy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2IDEfKFL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0rSymidU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i0XIaf1t_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_SazJp6hE, 0, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mprK3PVr, m);
}

void Heavy_EP_MK1::cBinop_20OqfaGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_jZbyfo4f_sendMessage);
}

void Heavy_EP_MK1::cBinop_jZbyfo4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0uc0zW84, HV_BINOP_POW, 1, m, &cBinop_0uc0zW84_sendMessage);
  cMsg_kb4IGhUs_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_0uc0zW84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_9GkGoUNy_sendMessage);
}

void Heavy_EP_MK1::cMsg_kb4IGhUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0uc0zW84, HV_BINOP_POW, 0, m, &cBinop_0uc0zW84_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_rMfZDNZW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_DCIzo1or_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_DCIzo1or_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Gn9nia4s, 1, m, &cDelay_Gn9nia4s_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xgotwYzR_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_Gn9nia4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Gn9nia4s, m);
  cPack_onMessage(_c, &Context(_c)->cPack_0FFsXUe9, 0, m, &cPack_0FFsXUe9_sendMessage);
}

void Heavy_EP_MK1::cMsg_DCIzo1or_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gn9nia4s, 0, m, &cDelay_Gn9nia4s_sendMessage);
}

void Heavy_EP_MK1::cCast_xgotwYzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gn9nia4s, 0, m, &cDelay_Gn9nia4s_sendMessage);
}

void Heavy_EP_MK1::cPack_0FFsXUe9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ISJj7OwQ_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_UWPDyIY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_mEI45YN0_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_5Qfl8Kl3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_QC38XxDe, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_kyiC1Zf2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A5QHofQ9, HV_BINOP_MULTIPLY, 0, m, &cBinop_A5QHofQ9_sendMessage);
}

void Heavy_EP_MK1::cMsg_hDZvWMG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AIHWizth_sendMessage);
}

void Heavy_EP_MK1::cSystem_AIHWizth_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FBLUET1E_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_A5QHofQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_IMhCCKPw_sendMessage);
}

void Heavy_EP_MK1::cBinop_D136IKQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A5QHofQ9, HV_BINOP_MULTIPLY, 1, m, &cBinop_A5QHofQ9_sendMessage);
}

void Heavy_EP_MK1::cMsg_FBLUET1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_D136IKQ5_sendMessage);
}

void Heavy_EP_MK1::cBinop_IMhCCKPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_r1TUkR2L_sendMessage);
}

void Heavy_EP_MK1::cBinop_r1TUkR2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_CZyqnm4Q_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_4J0MldFm, m);
}

void Heavy_EP_MK1::cBinop_CZyqnm4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yvUDRhOv, m);
}

void Heavy_EP_MK1::cSwitchcase_4cD0pfyC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_CoaLfaFv_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_CoaLfaFv_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_i2j9vtBd, 1, m, &cDelay_i2j9vtBd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_grCwKwJK_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_i2j9vtBd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_i2j9vtBd, m);
  cPack_onMessage(_c, &Context(_c)->cPack_EgibIsHG, 0, m, &cPack_EgibIsHG_sendMessage);
}

void Heavy_EP_MK1::cMsg_CoaLfaFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_i2j9vtBd, 0, m, &cDelay_i2j9vtBd_sendMessage);
}

void Heavy_EP_MK1::cCast_grCwKwJK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_i2j9vtBd, 0, m, &cDelay_i2j9vtBd_sendMessage);
}

void Heavy_EP_MK1::cPack_EgibIsHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vVR1067u_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cSlice_nx6xWTIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_wPGSZ374_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_nRibR7JK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_U2PPTpXa, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cVar_2ZeHP4qZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3GYF4I39, HV_BINOP_MULTIPLY, 0, m, &cBinop_3GYF4I39_sendMessage);
}

void Heavy_EP_MK1::cMsg_eFIgSVQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rVjKxSWj_sendMessage);
}

void Heavy_EP_MK1::cSystem_rVjKxSWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HRfxxP3f_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_3GYF4I39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iAd21jN7_sendMessage);
}

void Heavy_EP_MK1::cBinop_FyKBZYzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3GYF4I39, HV_BINOP_MULTIPLY, 1, m, &cBinop_3GYF4I39_sendMessage);
}

void Heavy_EP_MK1::cMsg_HRfxxP3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_FyKBZYzr_sendMessage);
}

void Heavy_EP_MK1::cBinop_iAd21jN7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_JuAm7KIS_sendMessage);
}

void Heavy_EP_MK1::cBinop_JuAm7KIS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_wkitl7VS_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_w0y5ojuv, m);
}

void Heavy_EP_MK1::cBinop_wkitl7VS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_14rNbRoM, m);
}

void Heavy_EP_MK1::cSwitchcase_AlMaGzAy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ccZGSBP7, 0, m, &cSlice_ccZGSBP7_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ljp9kzNl, 0, m, &cSlice_Ljp9kzNl_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_ccZGSBP7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_20OqfaGo_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_20OqfaGo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSlice_Ljp9kzNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_GLx6aHXJ_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_GLx6aHXJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cBinop_HMJc0N5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f66uQpzU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jQ3DV4oR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rp4fOhNx_sendMessage);
}

void Heavy_EP_MK1::cBinop_GLx6aHXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_14YQ1uDS_sendMessage);
}

void Heavy_EP_MK1::cBinop_14YQ1uDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CWI2ECk7, HV_BINOP_POW, 1, m, &cBinop_CWI2ECk7_sendMessage);
  cMsg_L5ydR6Yi_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_CWI2ECk7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_HMJc0N5e_sendMessage);
}

void Heavy_EP_MK1::cMsg_L5ydR6Yi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CWI2ECk7, HV_BINOP_POW, 0, m, &cBinop_CWI2ECk7_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_4Oxw3M2i_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lDCkN1Kf_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_lDCkN1Kf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vNxezH8y_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wrpHr5h4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2B0squbx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xEnOiPtC_sendMessage);
  cSwitchcase_QCOcZL0k_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_aIK2Du5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_REqzQemd_sendMessage);
}

void Heavy_EP_MK1::cSystem_REqzQemd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xbpI8lwe, m);
}

void Heavy_EP_MK1::cMsg_mUqtQDle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_p9cn2unM_sendMessage);
}

void Heavy_EP_MK1::cSystem_p9cn2unM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DiXqbjFE, m);
}

void Heavy_EP_MK1::cDelay_3FZn93hs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3FZn93hs, m);
  cPack_onMessage(_c, &Context(_c)->cPack_knDzxs63, 0, m, &cPack_knDzxs63_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_m0cBL5CC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_4t6Hq55c_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_4t6Hq55c_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_rYvigZyQ, 1, m, &cDelay_rYvigZyQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3Szlj56g_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_rYvigZyQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rYvigZyQ, m);
  cMsg_b60XF5JT_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_4t6Hq55c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rYvigZyQ, 0, m, &cDelay_rYvigZyQ_sendMessage);
}

void Heavy_EP_MK1::cCast_3Szlj56g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rYvigZyQ, 0, m, &cDelay_rYvigZyQ_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_8EwDqalS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_v5mHUs55_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_v5mHUs55_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_El2I9C77, 1, m, &cDelay_El2I9C77_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xdGIes8s_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_El2I9C77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_El2I9C77, m);
  cMsg_UThFMZyR_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_v5mHUs55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_El2I9C77, 0, m, &cDelay_El2I9C77_sendMessage);
}

void Heavy_EP_MK1::cCast_xdGIes8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_El2I9C77, 0, m, &cDelay_El2I9C77_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_QCOcZL0k_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_DFPVnsBM_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_DFPVnsBM_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_IQg5PLnG, 1, m, &cDelay_IQg5PLnG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NqAjhx31_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_IQg5PLnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IQg5PLnG, m);
  cMsg_FVIIT6ue_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_DFPVnsBM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IQg5PLnG, 0, m, &cDelay_IQg5PLnG_sendMessage);
}

void Heavy_EP_MK1::cCast_NqAjhx31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IQg5PLnG, 0, m, &cDelay_IQg5PLnG_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_VNlVhLop_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ss1rlpM4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ss1rlpM4_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TfNYpGKV, 1, m, &cDelay_TfNYpGKV_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cEXkdH3i_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cDelay_TfNYpGKV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TfNYpGKV, m);
  cMsg_Tv18BrFM_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_ss1rlpM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TfNYpGKV, 0, m, &cDelay_TfNYpGKV_sendMessage);
}

void Heavy_EP_MK1::cCast_cEXkdH3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TfNYpGKV, 0, m, &cDelay_TfNYpGKV_sendMessage);
}

void Heavy_EP_MK1::cDelay_SQWhXbuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SQWhXbuK, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_vTikcOK9_sendMessage);
}

void Heavy_EP_MK1::cSwitchcase_4bJ7vNfF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_432gH9F6_sendMessage);
      break;
    }
    default: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_SQWhXbuK, 0, m, &cDelay_SQWhXbuK_sendMessage);
      break;
    }
  }
}

void Heavy_EP_MK1::cCast_432gH9F6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EP_MK1::cIf_7NsIHVOW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_57hlhbxL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_dx9EgukM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cMsg_8zJCSbxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JsfiF6qC, HV_BINOP_POW, 0, m, &cBinop_JsfiF6qC_sendMessage);
}

void Heavy_EP_MK1::cBinop_JsfiF6qC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_71RKkz2i, m);
}

void Heavy_EP_MK1::cBinop_7hjoygWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_HgHg89r7_sendMessage);
}

void Heavy_EP_MK1::cCast_P0nhFNeb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Pd5lqoR8_sendMessage);
}

void Heavy_EP_MK1::cCast_OR53sAy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7NsIHVOW, 0, m, &cIf_7NsIHVOW_sendMessage);
}

void Heavy_EP_MK1::cBinop_Pd5lqoR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7NsIHVOW, 1, m, &cIf_7NsIHVOW_sendMessage);
}

void Heavy_EP_MK1::cBinop_dx9EgukM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_7hjoygWC_sendMessage);
}

void Heavy_EP_MK1::cMsg_57hlhbxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_71RKkz2i, m);
}

void Heavy_EP_MK1::cBinop_HgHg89r7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JsfiF6qC, HV_BINOP_POW, 1, m, &cBinop_JsfiF6qC_sendMessage);
  cMsg_8zJCSbxV_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cPack_knDzxs63_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_12GlrbhH_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cBinop_Lo45ltl1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4Oxw3M2i_onMessage(_c, NULL, 0, m, NULL);
  cPack_onMessage(_c, &Context(_c)->cPack_knDzxs63, 1, m, &cPack_knDzxs63_sendMessage);
}

void Heavy_EP_MK1::cMsg_mbwAJXPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_PFUxS9Go_sendMessage);
}

void Heavy_EP_MK1::cBinop_PFUxS9Go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RHSLWQjL, HV_BINOP_MULTIPLY, 0, m, &cBinop_RHSLWQjL_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_17N4JcCh_sendMessage);
}

void Heavy_EP_MK1::cCast_7NAvYHLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_rMfZDNZW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_J9J1vN7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xWQxJdsi_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_ISJj7OwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_UWPDyIY4, 0, m, &cSlice_UWPDyIY4_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_5Qfl8Kl3, 0, m, &cSlice_5Qfl8Kl3_sendMessage);
}

void Heavy_EP_MK1::cMsg_mEI45YN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Q5wsYYlY_sendMessage);
}

void Heavy_EP_MK1::cBinop_Q5wsYYlY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kyiC1Zf2, 0, m, &cVar_kyiC1Zf2_sendMessage);
}

void Heavy_EP_MK1::cMsg_FVIIT6ue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_SazJp6hE, 1, m);
}

void Heavy_EP_MK1::cBinop_RHSLWQjL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0FFsXUe9, 1, m, &cPack_0FFsXUe9_sendMessage);
}

void Heavy_EP_MK1::cCast_wrpHr5h4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4HMeafoY_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_vNxezH8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8EwDqalS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_4HMeafoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_B8Rawwja, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_UThFMZyR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_B8Rawwja, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_QpX8KJ1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4cD0pfyC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_rk2leRf0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MMOQOcXb_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_vVR1067u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_nx6xWTIv, 0, m, &cSlice_nx6xWTIv_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_nRibR7JK, 0, m, &cSlice_nRibR7JK_sendMessage);
}

void Heavy_EP_MK1::cMsg_wPGSZ374_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_09LNF0Eg_sendMessage);
}

void Heavy_EP_MK1::cBinop_09LNF0Eg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2ZeHP4qZ, 0, m, &cVar_2ZeHP4qZ_sendMessage);
}

void Heavy_EP_MK1::cMsg_MMOQOcXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_nx6xWTIv, 0, m, &cSlice_nx6xWTIv_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_nRibR7JK, 0, m, &cSlice_nRibR7JK_sendMessage);
}

void Heavy_EP_MK1::cBinop_17N4JcCh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_EgibIsHG, 1, m, &cPack_EgibIsHG_sendMessage);
}

void Heavy_EP_MK1::cMsg_1YqmG8JV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 50.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_nx6xWTIv, 0, m, &cSlice_nx6xWTIv_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_nRibR7JK, 0, m, &cSlice_nRibR7JK_sendMessage);
}

void Heavy_EP_MK1::cCast_f66uQpzU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bXl02GUf_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_Rp4fOhNx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0FFsXUe9, 0, m, &cPack_0FFsXUe9_sendMessage);
}

void Heavy_EP_MK1::cCast_jQ3DV4oR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mbwAJXPL_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_0rSymidU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mbwAJXPL_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_2IDEfKFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ievitM3h_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cCast_i0XIaf1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J9J1vN7D_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7NAvYHLM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rk2leRf0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QpX8KJ1s_sendMessage);
}

void Heavy_EP_MK1::cMsg_ievitM3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2048.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RHSLWQjL, HV_BINOP_MULTIPLY, 1, m, &cBinop_RHSLWQjL_sendMessage);
}

void Heavy_EP_MK1::cCast_2B0squbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VNlVhLop_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cCast_xEnOiPtC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_m0cBL5CC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_Tv18BrFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_VEYj3jgK, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_b60XF5JT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20000.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_VEYj3jgK, 0, m, NULL);
}

void Heavy_EP_MK1::cMsg_xWQxJdsi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.1f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_UWPDyIY4, 0, m, &cSlice_UWPDyIY4_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_5Qfl8Kl3, 0, m, &cSlice_5Qfl8Kl3_sendMessage);
}

void Heavy_EP_MK1::cBinop_vTikcOK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 126.0f, 0, m, &cBinop_4LE3oFAE_sendMessage);
}

void Heavy_EP_MK1::cBinop_4LE3oFAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LbalmIoa_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cMsg_LbalmIoa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ghZEl5yM_sendMessage);
}

void Heavy_EP_MK1::cBinop_ghZEl5yM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -30.0f, 0, m, &cBinop_Af1mNKzv_sendMessage);
}

void Heavy_EP_MK1::cBinop_Af1mNKzv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_XzeBh5jF_sendMessage);
}

void Heavy_EP_MK1::cBinop_XzeBh5jF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P0nhFNeb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OR53sAy6_sendMessage);
}

void Heavy_EP_MK1::cMsg_bXl02GUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 8.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RHSLWQjL, HV_BINOP_MULTIPLY, 1, m, &cBinop_RHSLWQjL_sendMessage);
}

void Heavy_EP_MK1::cMsg_12GlrbhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_AlMaGzAy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cSwitchcase_oJjbF3oR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_05vVwRGe, 0, m, &cSlice_05vVwRGe_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_05vVwRGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_2INuIXhx, 0, m, &cSlice_2INuIXhx_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_rIS4wCWL, 0, m, &cSlice_rIS4wCWL_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_2INuIXhx, 0, m, &cSlice_2INuIXhx_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_rIS4wCWL, 0, m, &cSlice_rIS4wCWL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSwitchcase_CI4f9r5B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_c3nXiTNC, 0, m, &cSlice_c3nXiTNC_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_c3nXiTNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_qZT4eBYV, 0, m, &cSlice_qZT4eBYV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_7oNej4sG, 0, m, &cSlice_7oNej4sG_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_qZT4eBYV, 0, m, &cSlice_qZT4eBYV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_7oNej4sG, 0, m, &cSlice_7oNej4sG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSwitchcase_0kq1xuMz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x40800000: { // "4.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_z8G0G5Eb, 0, m, &cSlice_z8G0G5Eb_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_z8G0G5Eb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_hv3mUgaW, 0, m, &cSlice_hv3mUgaW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_XWrWDCcW, 0, m, &cSlice_XWrWDCcW_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_hv3mUgaW, 0, m, &cSlice_hv3mUgaW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_XWrWDCcW, 0, m, &cSlice_XWrWDCcW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSwitchcase_zGa1EpH7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x40A00000: { // "5.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2O5lvYJA, 0, m, &cSlice_2O5lvYJA_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_2O5lvYJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_jBZVqRID, 0, m, &cSlice_jBZVqRID_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZxsAnMyr, 0, m, &cSlice_ZxsAnMyr_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_jBZVqRID, 0, m, &cSlice_jBZVqRID_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZxsAnMyr, 0, m, &cSlice_ZxsAnMyr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSwitchcase_7i9NfnFn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x40C00000: { // "6.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_if4TiRX7, 0, m, &cSlice_if4TiRX7_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_if4TiRX7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_YdkTn2WL, 0, m, &cSlice_YdkTn2WL_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_IDtSoCz3, 0, m, &cSlice_IDtSoCz3_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_YdkTn2WL, 0, m, &cSlice_YdkTn2WL_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_IDtSoCz3, 0, m, &cSlice_IDtSoCz3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSwitchcase_nPhn8cUn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x40E00000: { // "7.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lpM95DRE, 0, m, &cSlice_lpM95DRE_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_lpM95DRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_DP57ivEA, 0, m, &cSlice_DP57ivEA_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Jed3KeQW, 0, m, &cSlice_Jed3KeQW_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_DP57ivEA, 0, m, &cSlice_DP57ivEA_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Jed3KeQW, 0, m, &cSlice_Jed3KeQW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSwitchcase_ZvI2MPL9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x41000000: { // "8.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GQUD4Nul, 0, m, &cSlice_GQUD4Nul_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_EP_MK1::cSlice_GQUD4Nul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_kpwhR0tf, 0, m, &cSlice_kpwhR0tf_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_oh4auhT2, 0, m, &cSlice_oh4auhT2_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_kpwhR0tf, 0, m, &cSlice_kpwhR0tf_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_oh4auhT2, 0, m, &cSlice_oh4auhT2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EP_MK1::cSend_AOX5cBQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YUPT5gm3_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cReceive_30ra41Ne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mwVDhc33_sendMessage(_c, 0, m);
  cMsg_h5Bsj9K4_sendMessage(_c, 0, m);
  cMsg_fNVYmuRq_sendMessage(_c, 0, m);
  cMsg_FyHDrtsd_sendMessage(_c, 0, m);
  cMsg_vnInM2TA_sendMessage(_c, 0, m);
  cMsg_zX4gvtjh_sendMessage(_c, 0, m);
  cMsg_lYOaGMwk_sendMessage(_c, 0, m);
  cMsg_7KV6tt6Z_sendMessage(_c, 0, m);
  cMsg_ug9sv1mV_sendMessage(_c, 0, m);
  cMsg_37gYBrZv_sendMessage(_c, 0, m);
  cMsg_duSEFOQ2_sendMessage(_c, 0, m);
  cMsg_OmjfJHO2_sendMessage(_c, 0, m);
  cMsg_w9j1Cdjk_sendMessage(_c, 0, m);
  cMsg_dHvyDREf_sendMessage(_c, 0, m);
  cMsg_aIK2Du5A_sendMessage(_c, 0, m);
  cMsg_mUqtQDle_sendMessage(_c, 0, m);
  cMsg_iKXnugbR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sZ2r4PVf, 0, m, &cVar_sZ2r4PVf_sendMessage);
  cMsg_JMXe4Ma3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NTVGi1rx, 0, m, &cVar_NTVGi1rx_sendMessage);
  cMsg_emXeKopE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_f7mZhooZ, 0, m, &cVar_f7mZhooZ_sendMessage);
  cMsg_fxp86nbP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cuvWDrFY, 0, m, &cVar_cuvWDrFY_sendMessage);
  cMsg_xUIk35fz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_I5axLBa7, 0, m, &cVar_I5axLBa7_sendMessage);
  cMsg_Axz1orYI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6lY50lnm, 0, m, &cVar_6lY50lnm_sendMessage);
  cMsg_EZLaZJk9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_r5ixlHEt, 0, m, &cVar_r5ixlHEt_sendMessage);
  cMsg_cGPaQMM6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9G2w7qnP, 0, m, &cVar_9G2w7qnP_sendMessage);
  cMsg_0b6oTzRv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_43FOqtBR, 0, m, &cVar_43FOqtBR_sendMessage);
  cMsg_pkFtiTnu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PQrhAZRa, 0, m, &cVar_PQrhAZRa_sendMessage);
  cMsg_0KIBKjcE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mrGWo2hl, 0, m, &cVar_mrGWo2hl_sendMessage);
  cMsg_lBdzS1y9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2nrwCzMG, 0, m, &cVar_2nrwCzMG_sendMessage);
  cMsg_KXtXNOXa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JD9szZbV, 0, m, &cVar_JD9szZbV_sendMessage);
  cMsg_qRQ3L6AU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_81HDz8CE, 0, m, &cVar_81HDz8CE_sendMessage);
  cMsg_hDZvWMG1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kyiC1Zf2, 0, m, &cVar_kyiC1Zf2_sendMessage);
  cMsg_eFIgSVQb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2ZeHP4qZ, 0, m, &cVar_2ZeHP4qZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cpIi4bZm, 0, m, &cVar_cpIi4bZm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_QDfjXuFO, 0, m, &cVar_QDfjXuFO_sendMessage);
  cMsg_XSFgs2Vd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ElxPJUxK, 0, m, &cVar_ElxPJUxK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gjG7vzxq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GXrq5eSO_sendMessage);
}

void Heavy_EP_MK1::cReceive_xufwxl2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_elndZqvG, 0, m, &cSlice_elndZqvG_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_8lQZHtLi, 0, m, &cSlice_8lQZHtLi_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_YVJyinnD, 0, m, &cSlice_YVJyinnD_sendMessage);
  cMsg_nPKwQsvv_sendMessage(_c, 0, m);
}

void Heavy_EP_MK1::cReceive_YUPT5gm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_oG9J2dvF_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_oJjbF3oR_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_CI4f9r5B_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_0kq1xuMz_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_zGa1EpH7_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_7i9NfnFn_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_nPhn8cUn_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_ZvI2MPL9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_EP_MK1::cReceive_MGnMGx0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5c1hNZPU, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7rNwdeBI, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_sna6KPtA, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_2h60wK8h, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3PZoK8Te, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_p9lZuVC3, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JwE9URmy, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Zj8nnBuC, m);
}

void Heavy_EP_MK1::cReceive_78vPaVrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_30KS2vcA, 1, m, &cIf_30KS2vcA_sendMessage);
}

void Heavy_EP_MK1::cReceive_Yvc0SbVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FxOwbdbW, 1, m, &cVar_FxOwbdbW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_u5tBj8Lb, 1, m, &cVar_u5tBj8Lb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GiSxSddZ, 1, m, &cVar_GiSxSddZ_sendMessage);
}

void Heavy_EP_MK1::cReceive_RehAy77I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t9FMWBot, 0, m, &cVar_t9FMWBot_sendMessage);
}

void Heavy_EP_MK1::cReceive_VHVO9aGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uyfxho1R, 1, m, &cVar_uyfxho1R_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MitV4kWM, 1, m, &cVar_MitV4kWM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_60vLkGOw, HV_BINOP_MOD_UNIPOLAR, 1, m, &cBinop_60vLkGOw_sendMessage);
}

void Heavy_EP_MK1::cReceive_T5RYnxvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_AFpLtIy7, 1, m, &cTabwrite_AFpLtIy7_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_rhy4zqC2, 1, m, &cTabwrite_rhy4zqC2_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_ZnyIyMwB, 1, m, &cTabwrite_ZnyIyMwB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bNgyqWRz, 1, m, &cVar_bNgyqWRz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_L9vaHYGJ, 1, m, &cVar_L9vaHYGJ_sendMessage);
}

void Heavy_EP_MK1::cReceive_xWrZfXcb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MfvQWInI, 1, m, &cVar_MfvQWInI_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_b1zrUtiJ, 1, m, &cTabwrite_b1zrUtiJ_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_7CqRGpzh, 1, m, &cTabwrite_7CqRGpzh_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_f431WPJL, 1, m, &cTabwrite_f431WPJL_sendMessage);
}

void Heavy_EP_MK1::cReceive_YSOymCGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xqKm824T_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_E0zeqvEo_sendMessage);
}

void Heavy_EP_MK1::cReceive_UNQwjlFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WmFpuX9z_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hpLxvQwg_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_EP_MK1::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12, Bf13;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_var_k_f(VOf(Bf0), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_varread_f(&sVarf_mmQmNb4h, VOf(Bf1));
    __hv_varread_f(&sVarf_JStffWNs, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_12WWjECf, VOf(Bf1));
    __hv_rpole_f(&sRPole_xQE1l5IP, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_1g348lth, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf6));
    __hv_sub_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf8), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf6), VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf8));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf3), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf8), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_div_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_U88OzJYl, VOf(Bf5));
    __hv_varread_f(&sVarf_dWTru9Kp, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_MhpLVcYQ, VOf(Bf5));
    __hv_rpole_f(&sRPole_LJ2U55sy, VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_E7C2HtOj, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_p3apF6qw, VOf(Bf4));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_line_f(&sLine_Fe0sHHrh, VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf9), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_div_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_0vvlNiX4, VOf(Bf2));
    __hv_div_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf8));
    __hv_sub_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf8));
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf11), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf8), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf12), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_div_f(VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_floor_f(VIf(Bf2), VOf(Bf11));
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf11));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf11), VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf6), VIf(Bf10), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf6), VIf(Bf10), VOf(Bf6));
    __hv_mul_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_biquad_f(&sBiquad_s_YKOSCulY, VIf(Bf1), VIf(Bf5), VIf(Bf6), VIf(Bf2), VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_min_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f);
    __hv_max_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f);
    __hv_var_k_f(VOf(Bf5), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_fma_f(VIf(Bf9), VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_div_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf11), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf5));
    __hv_pow_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_pow_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_div_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf5), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_pow_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_5c1hNZPU, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf11), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_pkqNsRE6, VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf6), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_min_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_div_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_yz2BQm5L, VOf(Bf2));
    __hv_div_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf6), VIf(Bf1), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf12), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_div_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf2), VOf(Bf11));
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf11));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf6), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf11), VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_neg_f(VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf12), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_biquad_f(&sBiquad_s_WwgL7LgK, VIf(Bf5), VIf(Bf11), VIf(Bf6), VIf(Bf1), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_div_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_varread_f(&sVarf_lvEgPbs3, VOf(Bf3));
    __hv_varread_f(&sVarf_RcnTHRuu, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_WD7C8chd, VOf(Bf3));
    __hv_rpole_f(&sRPole_Yh3y0fv7, VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_fT5BH6mJ, VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf6));
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf6), VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf5), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf5));
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf11), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf5), VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf11), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf0), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf1), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_div_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_iDRS34B2, VOf(Bf11));
    __hv_varread_f(&sVarf_vp8lIXCn, VOf(Bf1));
    __hv_mul_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_MfT4ifW4, VOf(Bf11));
    __hv_rpole_f(&sRPole_OW9MoKMh, VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf6), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf3), VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_3qDPWnPQ, VOf(Bf12));
    __hv_mul_f(VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_line_f(&sLine_hADdbIyX, VOf(Bf6));
    __hv_mul_f(VIf(Bf12), VIf(Bf6), VOf(Bf12));
    __hv_var_k_f(VOf(Bf3), 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f);
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf11), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_line_f(&sLine_QOlaVO7i, VOf(Bf1));
    __hv_add_f(VIf(Bf11), VIf(Bf1), VOf(Bf11));
    __hv_var_k_f(VOf(Bf0), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf9), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_div_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_qx7mJTO2, VOf(Bf2));
    __hv_div_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf0));
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf0));
    __hv_mul_f(VIf(Bf11), VIf(Bf0), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf8), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf10), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_div_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_floor_f(VIf(Bf2), VOf(Bf8));
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf8));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf11), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf8), VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf5), VIf(Bf10), VOf(Bf5));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf5), VIf(Bf10), VOf(Bf5));
    __hv_mul_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf13), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_biquad_f(&sBiquad_s_J2SXmwLe, VIf(Bf3), VIf(Bf11), VIf(Bf5), VIf(Bf2), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_min_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f);
    __hv_max_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f);
    __hv_var_k_f(VOf(Bf11), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_fma_f(VIf(Bf9), VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_div_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf8), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf11), VIf(Bf8), VOf(Bf11));
    __hv_pow_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_pow_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_div_f(VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf11), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_pow_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_7rNwdeBI, VOf(Bf2));
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_EnIDOsdo, VOf(Bf7));
    __hv_add_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf5), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_min_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_div_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_Jiw4Es3V, VOf(Bf2));
    __hv_div_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_div_f(VIf(Bf8), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf2), VOf(Bf8));
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf8));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf8), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf13), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_neg_f(VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_biquad_f(&sBiquad_s_V1GxOo38, VIf(Bf11), VIf(Bf8), VIf(Bf5), VIf(Bf3), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf6), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_div_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_varread_f(&sVarf_1ozkl1Ar, VOf(Bf12));
    __hv_varread_f(&sVarf_oj8tkGiB, VOf(Bf1));
    __hv_mul_f(VIf(Bf12), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_sChqoevv, VOf(Bf12));
    __hv_rpole_f(&sRPole_fc8fozRB, VIf(Bf1), VIf(Bf12), VOf(Bf12));
    __hv_phasor_k_f(&sPhasor_4cjQsVOb, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf8), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf3), VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf8), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf1), VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf8));
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf8));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf8), VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf5), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf13), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf1), VIf(Bf13), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf13));
    __hv_sub_f(VIf(Bf8), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf13));
    __hv_mul_f(VIf(Bf8), VIf(Bf13), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf2), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf13), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_div_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_zeHbGhXt, VOf(Bf5));
    __hv_varread_f(&sVarf_WSO3zyqT, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_r2nB2y1m, VOf(Bf5));
    __hv_rpole_f(&sRPole_mUTFYoDS, VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_NOYgXabI, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_cIX3zJqu, VOf(Bf3));
    __hv_mul_f(VIf(Bf11), VIf(Bf3), VOf(Bf11));
    __hv_var_k_f(VOf(Bf12), 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f);
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf5), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_line_f(&sLine_LhlRTRkY, VOf(Bf2));
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf5));
    __hv_var_k_f(VOf(Bf13), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf7), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf13), VIf(Bf7), VOf(Bf7));
    __hv_div_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_ruyibc4Y, VOf(Bf1));
    __hv_div_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf13));
    __hv_sub_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf13));
    __hv_mul_f(VIf(Bf5), VIf(Bf13), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf13), VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_div_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_floor_f(VIf(Bf1), VOf(Bf10));
    __hv_sub_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf10));
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf10), VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf10));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf10), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_biquad_f(&sBiquad_s_yl5UTiMA, VIf(Bf12), VIf(Bf5), VIf(Bf8), VIf(Bf1), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_min_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f);
    __hv_max_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf8), 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f);
    __hv_var_k_f(VOf(Bf5), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_div_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf10), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf5), VIf(Bf10), VOf(Bf5));
    __hv_pow_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf1), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_pow_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_div_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf5), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_pow_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_sna6KPtA, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf10), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_e5DnsKGN, VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf8), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_min_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_div_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_zp8XrZmD, VOf(Bf1));
    __hv_div_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf8));
    __hv_sub_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf12), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf8), VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_div_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf1), VOf(Bf10));
    __hv_sub_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf10));
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf10), VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_neg_f(VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf12), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf1), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_biquad_f(&sBiquad_s_w1lsyZ09, VIf(Bf5), VIf(Bf10), VIf(Bf8), VIf(Bf12), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf3), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_div_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_varread_f(&sVarf_kx1tzfa7, VOf(Bf11));
    __hv_varread_f(&sVarf_7O0Uks8x, VOf(Bf2));
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_DyUZzAkb, VOf(Bf11));
    __hv_rpole_f(&sRPole_6w5YBg62, VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_phasor_k_f(&sPhasor_D5sKYl8D, VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf12), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf12), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf12), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf12));
    __hv_mul_f(VIf(Bf1), VIf(Bf12), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf12), VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf10), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_var_k_f(VOf(Bf12), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf10));
    __hv_sub_f(VIf(Bf12), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf12), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_abs_f(VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf12), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf12), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf12), VOf(Bf10));
    __hv_mul_f(VIf(Bf12), VIf(Bf10), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf10), VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf8), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf0), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf0));
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_abs_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf10), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf0));
    __hv_mul_f(VIf(Bf10), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf12), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf1), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf12), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf12), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_div_f(VIf(Bf1), VIf(Bf12), VOf(Bf12));
    __hv_add_f(VIf(Bf8), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_nFQtbdVq, VOf(Bf8));
    __hv_varread_f(&sVarf_8A33dqbR, VOf(Bf1));
    __hv_mul_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_K4mxXcbU, VOf(Bf8));
    __hv_rpole_f(&sRPole_RSpjeLQ7, VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf12), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf12), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf8), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf11), VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_gMuBQaiz, VOf(Bf5));
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_0sWTZ5AU, VOf(Bf12));
    __hv_mul_f(VIf(Bf5), VIf(Bf12), VOf(Bf5));
    __hv_var_k_f(VOf(Bf11), 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f);
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf8), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_line_f(&sLine_RzEGSGrh, VOf(Bf1));
    __hv_add_f(VIf(Bf8), VIf(Bf1), VOf(Bf8));
    __hv_var_k_f(VOf(Bf0), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf4), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_div_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_LGgQiJgX, VOf(Bf2));
    __hv_div_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf0));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf0));
    __hv_mul_f(VIf(Bf8), VIf(Bf0), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf8), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf0), VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_div_f(VIf(Bf10), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_floor_f(VIf(Bf2), VOf(Bf9));
    __hv_sub_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf9), VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf10), VIf(Bf7), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf13), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf10), VIf(Bf7), VOf(Bf10));
    __hv_mul_f(VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf9), VIf(Bf7), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_biquad_f(&sBiquad_s_RKAk6kYo, VIf(Bf11), VIf(Bf8), VIf(Bf10), VIf(Bf2), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_min_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f);
    __hv_max_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf10), 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f);
    __hv_var_k_f(VOf(Bf8), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_fma_f(VIf(Bf4), VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_div_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_pow_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_pow_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_div_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf8), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_pow_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_2h60wK8h, VOf(Bf2));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf9), VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_4WWOmkn4, VOf(Bf6));
    __hv_add_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf10), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_min_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf1), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_div_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_tfwRhNIy, VOf(Bf2));
    __hv_div_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf10));
    __hv_sub_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf6), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf10));
    __hv_mul_f(VIf(Bf6), VIf(Bf10), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf11), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf6), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf10), VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_div_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf2), VOf(Bf9));
    __hv_sub_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_neg_f(VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_biquad_f(&sBiquad_s_tKqK3PD8, VIf(Bf8), VIf(Bf9), VIf(Bf10), VIf(Bf11), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf1), VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf12), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_div_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_add_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf3), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_varread_f(&sVarf_4tw7syWZ, VOf(Bf5));
    __hv_varread_f(&sVarf_Q2qDb61i, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_P4bF2htA, VOf(Bf5));
    __hv_rpole_f(&sRPole_rortzBCV, VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_EcWjv2sM, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf11));
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf11));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf8), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf11), VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf1), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf9));
    __hv_sub_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf9));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf10), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf13), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf1), VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf13));
    __hv_sub_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf13));
    __hv_mul_f(VIf(Bf9), VIf(Bf13), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf11), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf2), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf13), VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_div_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_Uj8v2gts, VOf(Bf10));
    __hv_varread_f(&sVarf_9lhwrhxA, VOf(Bf2));
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Gzvbv7EO, VOf(Bf10));
    __hv_rpole_f(&sRPole_h1PimpFg, VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf11), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_QndJgocL, VOf(Bf8));
    __hv_mul_f(VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_dkF12Ve6, VOf(Bf11));
    __hv_mul_f(VIf(Bf8), VIf(Bf11), VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f);
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf10), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_line_f(&sLine_qf13Df9a, VOf(Bf2));
    __hv_add_f(VIf(Bf10), VIf(Bf2), VOf(Bf10));
    __hv_var_k_f(VOf(Bf13), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf6), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf13), VIf(Bf6), VOf(Bf6));
    __hv_div_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf10), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_gG3oyfVr, VOf(Bf1));
    __hv_div_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf13));
    __hv_sub_f(VIf(Bf10), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_abs_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf10), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf13));
    __hv_mul_f(VIf(Bf10), VIf(Bf13), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf7), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf13), VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_div_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_floor_f(VIf(Bf1), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf7), VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf9), VIf(Bf4), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf9), VIf(Bf4), VOf(Bf9));
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf7), VIf(Bf4), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_5ZyVy244, VIf(Bf5), VIf(Bf10), VIf(Bf9), VIf(Bf1), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf7), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_min_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf7), -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f);
    __hv_max_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_add_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf9), 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f);
    __hv_var_k_f(VOf(Bf10), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_fma_f(VIf(Bf6), VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_div_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf10));
    __hv_pow_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf1), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_pow_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_div_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf10), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_pow_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_3PZoK8Te, VOf(Bf1));
    __hv_mul_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf7), VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_7P4pkLFI, VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_min_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_div_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_LJPeQeRw, VOf(Bf1));
    __hv_div_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf9));
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf9), VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_div_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf1), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf3), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf7), VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_neg_f(VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_biquad_f(&sBiquad_s_iY0l9PpE, VIf(Bf10), VIf(Bf7), VIf(Bf9), VIf(Bf5), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf2), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf11), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_div_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf12), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_varread_f(&sVarf_9dY6u1g9, VOf(Bf8));
    __hv_varread_f(&sVarf_ya0UY0D5, VOf(Bf2));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_WdJqQKz5, VOf(Bf8));
    __hv_rpole_f(&sRPole_ENY5kCjf, VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_phasor_k_f(&sPhasor_E5G3BDc3, VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf5));
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf7));
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf7), VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf0), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf0));
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf7), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf0));
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf1), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_div_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_Tln43Iuf, VOf(Bf9));
    __hv_varread_f(&sVarf_lbmQbBe1, VOf(Bf1));
    __hv_mul_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_QJuMdqAL, VOf(Bf9));
    __hv_rpole_f(&sRPole_FcnY2nUH, VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf8), VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_jkwvGNGq, VOf(Bf10));
    __hv_mul_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_7VShF34d, VOf(Bf5));
    __hv_mul_f(VIf(Bf10), VIf(Bf5), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f);
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_line_f(&sLine_cB6SyVDf, VOf(Bf1));
    __hv_add_f(VIf(Bf9), VIf(Bf1), VOf(Bf9));
    __hv_var_k_f(VOf(Bf0), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf3), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_div_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_bwlmwK6X, VOf(Bf2));
    __hv_div_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf0));
    __hv_sub_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf0));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_div_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_floor_f(VIf(Bf2), VOf(Bf4));
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf4), VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf13), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf4), VIf(Bf6), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_biquad_f(&sBiquad_s_lTst5uXH, VIf(Bf8), VIf(Bf9), VIf(Bf7), VIf(Bf2), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_min_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f);
    __hv_max_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f);
    __hv_var_k_f(VOf(Bf9), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_fma_f(VIf(Bf3), VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_div_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf9));
    __hv_pow_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf12), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_pow_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_div_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf12), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf9), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_pow_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_p9lZuVC3, VOf(Bf2));
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf4), VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_2VaBCHEQ, VOf(Bf12));
    __hv_add_f(VIf(Bf1), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf1), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf7), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_min_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_div_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf12), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_LY96DS0r, VOf(Bf2));
    __hv_div_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf12), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf7));
    __hv_sub_f(VIf(Bf12), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf12), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_abs_f(VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf12), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf12), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf12), VOf(Bf7));
    __hv_mul_f(VIf(Bf12), VIf(Bf7), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_div_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf2), VOf(Bf4));
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf8), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf4), VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf7), VOf(Bf7));
    __hv_neg_f(VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf13), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf13), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf12), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf12), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_biquad_f(&sBiquad_s_bv0ayvgN, VIf(Bf9), VIf(Bf4), VIf(Bf7), VIf(Bf8), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf1), VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf5), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_div_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf11), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_varread_f(&sVarf_kZnFwfGv, VOf(Bf10));
    __hv_varread_f(&sVarf_1LU3jUnE, VOf(Bf1));
    __hv_mul_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_fNWQjrL4, VOf(Bf10));
    __hv_rpole_f(&sRPole_KtL4KXWw, VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_phasor_k_f(&sPhasor_c7vJg0xU, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf8));
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf8));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf8), VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf1), VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf4));
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf8), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf4), VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf7), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf13), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf13), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf1), VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf13));
    __hv_sub_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf13));
    __hv_mul_f(VIf(Bf4), VIf(Bf13), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf8), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf2), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf13), VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_div_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_uSJzSkBR, VOf(Bf7));
    __hv_varread_f(&sVarf_H49aKc1Z, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_XOZLXNvW, VOf(Bf7));
    __hv_rpole_f(&sRPole_rXfoSWbc, VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf10), VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_OHtE4ZXn, VOf(Bf9));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_j9bBmCVa, VOf(Bf8));
    __hv_mul_f(VIf(Bf9), VIf(Bf8), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f);
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_line_f(&sLine_sg8Xev4V, VOf(Bf2));
    __hv_add_f(VIf(Bf7), VIf(Bf2), VOf(Bf7));
    __hv_var_k_f(VOf(Bf13), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf12), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf13), VIf(Bf12), VOf(Bf12));
    __hv_div_f(VIf(Bf1), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf1), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_tRrgHLef, VOf(Bf1));
    __hv_div_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf13));
    __hv_sub_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf7), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf13));
    __hv_mul_f(VIf(Bf7), VIf(Bf13), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf6), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf13), VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf12), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_div_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_floor_f(VIf(Bf1), VOf(Bf6));
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf7), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf3), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf6), VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_biquad_f(&sBiquad_s_cMP1tQbF, VIf(Bf10), VIf(Bf7), VIf(Bf4), VIf(Bf1), VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf6), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf12), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_min_f(VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf6), -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f);
    __hv_max_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf12));
    __hv_var_k_f(VOf(Bf1), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f);
    __hv_var_k_f(VOf(Bf7), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_fma_f(VIf(Bf12), VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_div_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_pow_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf1), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_pow_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_div_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf7), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_pow_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_JwE9URmy, VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf6), VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_wMKdFxWD, VOf(Bf11));
    __hv_add_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf4), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_min_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_div_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf11), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_jvcAXwqO, VOf(Bf1));
    __hv_div_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf4), VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_div_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf1), VOf(Bf6));
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf6), VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_neg_f(VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf1), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_biquad_f(&sBiquad_s_gmGyDRT9, VIf(Bf7), VIf(Bf6), VIf(Bf4), VIf(Bf10), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf2), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_div_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_varread_f(&sVarf_QC38XxDe, VOf(Bf9));
    __hv_varread_f(&sVarf_4J0MldFm, VOf(Bf2));
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_yvUDRhOv, VOf(Bf9));
    __hv_rpole_f(&sRPole_hqPZA51z, VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_phasor_k_f(&sPhasor_SazJp6hE, VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf10));
    __hv_sub_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf10));
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf6), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf10), VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf6));
    __hv_sub_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_abs_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf10), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf6));
    __hv_mul_f(VIf(Bf10), VIf(Bf6), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf6), VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf0));
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf1), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf10), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_div_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_U2PPTpXa, VOf(Bf4));
    __hv_varread_f(&sVarf_w0y5ojuv, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_14rNbRoM, VOf(Bf4));
    __hv_rpole_f(&sRPole_i1z0QzqD, VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf10), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf9), VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_71RKkz2i, VOf(Bf7));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_B8Rawwja, VOf(Bf10));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf7));
    __hv_var_k_f(VOf(Bf9), 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f);
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_line_f(&sLine_VEYj3jgK, VOf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf11), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_div_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_xbpI8lwe, VOf(Bf2));
    __hv_div_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf0));
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_div_f(VIf(Bf6), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_floor_f(VIf(Bf2), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf6), VIf(Bf12), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf6), VIf(Bf12), VOf(Bf6));
    __hv_mul_f(VIf(Bf13), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf12), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_biquad_f(&sBiquad_s_Tem2knmO, VIf(Bf9), VIf(Bf4), VIf(Bf6), VIf(Bf2), VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf3), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf11), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_min_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf3), -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f);
    __hv_max_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_add_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f);
    __hv_var_k_f(VOf(Bf4), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_fma_f(VIf(Bf11), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_div_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_pow_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_pow_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_div_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf4), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_pow_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_Zj8nnBuC, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_mprK3PVr, VOf(Bf5));
    __hv_add_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf6), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_min_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_div_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_DiXqbjFE, VOf(Bf2));
    __hv_div_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf6));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf6), VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_div_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf2), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_neg_f(VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf13), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_biquad_f(&sBiquad_s_LyFyGR1n, VIf(Bf4), VIf(Bf3), VIf(Bf6), VIf(Bf9), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf1), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_div_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_RNGFp3NA, VOf(Bf10));
    __hv_rpole_f(&sRPole_FWviEoDV, VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_GoFPXWmZ, VIf(Bf10), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_Yp4JGjbp, VOf(Bf10));
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf8), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf8), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_EP_MK1::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_EP_MK1::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
