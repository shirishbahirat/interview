

core_count = 64

clock_speed = 3.2

bits = 64

ddr_pins = 1

ddr6_per_pin_bw_GBps = 18/8

gen6_x16_BW_GBps_duplex = 256

number_of_dimm = 8

bw_gbpes_per_dimmm = 12.8

per_core_memory_processing = clock_speed * bits/8 * 2

print ("per core memory BW GB/s", per_core_memory_processing)

print (core_count, "core memory BW GB/s", per_core_memory_processing * core_count)

print ("pcie total BW with 128 lanes GB/s", per_core_memory_processing*128/16)

print ("per core PCIE BW GB/s", per_core_memory_processing*128/16/core_count)

network_bw_800GBps = 800/8

print("network BW total GB/w", network_bw_800GBps)

print("per core network BW GB/w", network_bw_800GBps/core_count)

print(bw_gbpes_per_dimmm * number_of_dimm)
