

core_count = 64

clock_speed = 4

bits = 64

ddr_pins = 1

ddr6_per_pin_bw_GBps = 24/8

gen6_x16_BW_GBps_duplex = 256

number_of_dimm = 1

capacity_per_dimm_gb = 24

bw_gbpes_per_dimmm = 12.8

per_core_memory_processing = clock_speed * bits/8 * 2

print ("per core memory BW GB/s", per_core_memory_processing)

print (core_count, "core memory BW GB/s", per_core_memory_processing * core_count)

print ("pcie total BW with 128 lanes GB/s", per_core_memory_processing*128/16)

print ("per core PCIE BW GB/s", per_core_memory_processing*128/16/core_count)

network_bw_800GBps = 800/8

print("network BW total GB/w", network_bw_800GBps)

print("per core network BW GB/w", network_bw_800GBps/core_count)

print(ddr6_per_pin_bw_GBps * 384 * number_of_dimm)

print("nvlink BW GB/s", 900)

nv link 6.25 GB/s 
pcie 4.0 2.0 GB/s 
