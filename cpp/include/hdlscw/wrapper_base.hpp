#ifndef HDLSCW_WRAPPER_BASE_INCLUDED
#define HDLSCW_WRAPPER_BASE_INCLUDED

#if defined(VERILATED_TRACE_ENABLED)
#include <verilated_vcd_c.h>
#endif // defined(VERILATED_TRACE_ENABLED)

namespace hdlscw {

struct wrapper_base {
    virtual sc_core::sc_module* getThisModule() noexcept = 0;
    virtual sc_core::sc_module const* getThisModule() const noexcept = 0;

    virtual sc_core::sc_module* getVerilatedModule() noexcept = 0;
    virtual sc_core::sc_module const* getVerilatedModule() const noexcept = 0;

    #if defined(VERILATED_TRACE_ENABLED)
    virtual void traceVerilated(VerilatedVcdC* tfp, int levels, int options = 0) {  }
    #endif // defined(VERILATED_TRACE_ENABLED)

    virtual ~wrapper_base() = default;
}; /* struct wrapper_base */

} /* namespace hdlscw */

#endif // HDLSCW_WRAPPER_BASE_INCLUDED
