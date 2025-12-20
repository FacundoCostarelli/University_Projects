// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.2 (win64) Build 5239630 Fri Nov 08 22:35:27 MST 2024
// Date        : Thu Oct  9 15:43:20 2025
// Host        : DESKTOP-38PF9T6 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim
//               c:/Users/Facun/Desktop/TD1_TPS_Locales/Exercise_Guide_Chapter_17/guia_17/guia_17.gen/sources_1/ip/ramMem/ramMem_sim_netlist.v
// Design      : ramMem
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z010iclg400-1L
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "ramMem,blk_mem_gen_v8_4_9,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_9,Vivado 2024.2" *) 
(* NotValidForBitStream *)
module ramMem
   (clka,
    wea,
    addra,
    dina,
    douta);
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA CLK" *) (* x_interface_mode = "slave BRAM_PORTA" *) (* x_interface_parameter = "XIL_INTERFACENAME BRAM_PORTA, MEM_ADDRESS_MODE BYTE_ADDRESS, MEM_SIZE 8192, MEM_WIDTH 32, MEM_ECC NONE, MASTER_TYPE OTHER, READ_LATENCY 1" *) input clka;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA WE" *) input [0:0]wea;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA ADDR" *) input [9:0]addra;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA DIN" *) input [15:0]dina;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA DOUT" *) output [15:0]douta;

  wire [9:0]addra;
  wire clka;
  wire [15:0]dina;
  wire [15:0]douta;
  wire [0:0]wea;
  wire NLW_U0_dbiterr_UNCONNECTED;
  wire NLW_U0_rsta_busy_UNCONNECTED;
  wire NLW_U0_rstb_busy_UNCONNECTED;
  wire NLW_U0_s_axi_arready_UNCONNECTED;
  wire NLW_U0_s_axi_awready_UNCONNECTED;
  wire NLW_U0_s_axi_bvalid_UNCONNECTED;
  wire NLW_U0_s_axi_dbiterr_UNCONNECTED;
  wire NLW_U0_s_axi_rlast_UNCONNECTED;
  wire NLW_U0_s_axi_rvalid_UNCONNECTED;
  wire NLW_U0_s_axi_sbiterr_UNCONNECTED;
  wire NLW_U0_s_axi_wready_UNCONNECTED;
  wire NLW_U0_sbiterr_UNCONNECTED;
  wire [15:0]NLW_U0_doutb_UNCONNECTED;
  wire [9:0]NLW_U0_rdaddrecc_UNCONNECTED;
  wire [3:0]NLW_U0_s_axi_bid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_bresp_UNCONNECTED;
  wire [9:0]NLW_U0_s_axi_rdaddrecc_UNCONNECTED;
  wire [15:0]NLW_U0_s_axi_rdata_UNCONNECTED;
  wire [3:0]NLW_U0_s_axi_rid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_rresp_UNCONNECTED;

  (* C_ADDRA_WIDTH = "10" *) 
  (* C_ADDRB_WIDTH = "10" *) 
  (* C_ALGORITHM = "1" *) 
  (* C_AXI_ID_WIDTH = "4" *) 
  (* C_AXI_SLAVE_TYPE = "0" *) 
  (* C_AXI_TYPE = "1" *) 
  (* C_BYTE_SIZE = "9" *) 
  (* C_COMMON_CLK = "0" *) 
  (* C_COUNT_18K_BRAM = "1" *) 
  (* C_COUNT_36K_BRAM = "0" *) 
  (* C_CTRL_ECC_ALGO = "NONE" *) 
  (* C_DEFAULT_DATA = "0" *) 
  (* C_DISABLE_WARN_BHV_COLL = "0" *) 
  (* C_DISABLE_WARN_BHV_RANGE = "0" *) 
  (* C_ELABORATION_DIR = "./" *) 
  (* C_ENABLE_32BIT_ADDRESS = "0" *) 
  (* C_EN_DEEPSLEEP_PIN = "0" *) 
  (* C_EN_ECC_PIPE = "0" *) 
  (* C_EN_RDADDRA_CHG = "0" *) 
  (* C_EN_RDADDRB_CHG = "0" *) 
  (* C_EN_SAFETY_CKT = "0" *) 
  (* C_EN_SHUTDOWN_PIN = "0" *) 
  (* C_EN_SLEEP_PIN = "0" *) 
  (* C_EST_POWER_SUMMARY = "Estimated Power for IP     :     1.442147 mW" *) 
  (* C_FAMILY = "zynq" *) 
  (* C_HAS_AXI_ID = "0" *) 
  (* C_HAS_ENA = "0" *) 
  (* C_HAS_ENB = "0" *) 
  (* C_HAS_INJECTERR = "0" *) 
  (* C_HAS_MEM_OUTPUT_REGS_A = "0" *) 
  (* C_HAS_MEM_OUTPUT_REGS_B = "0" *) 
  (* C_HAS_MUX_OUTPUT_REGS_A = "0" *) 
  (* C_HAS_MUX_OUTPUT_REGS_B = "0" *) 
  (* C_HAS_REGCEA = "0" *) 
  (* C_HAS_REGCEB = "0" *) 
  (* C_HAS_RSTA = "0" *) 
  (* C_HAS_RSTB = "0" *) 
  (* C_HAS_SOFTECC_INPUT_REGS_A = "0" *) 
  (* C_HAS_SOFTECC_OUTPUT_REGS_B = "0" *) 
  (* C_INITA_VAL = "0" *) 
  (* C_INITB_VAL = "0" *) 
  (* C_INIT_FILE = "ramMem.mem" *) 
  (* C_INIT_FILE_NAME = "no_coe_file_loaded" *) 
  (* C_INTERFACE_TYPE = "0" *) 
  (* C_LOAD_INIT_FILE = "0" *) 
  (* C_MEM_TYPE = "0" *) 
  (* C_MUX_PIPELINE_STAGES = "0" *) 
  (* C_PRIM_TYPE = "1" *) 
  (* C_READ_DEPTH_A = "1024" *) 
  (* C_READ_DEPTH_B = "1024" *) 
  (* C_READ_LATENCY_A = "1" *) 
  (* C_READ_LATENCY_B = "1" *) 
  (* C_READ_WIDTH_A = "16" *) 
  (* C_READ_WIDTH_B = "16" *) 
  (* C_RSTRAM_A = "0" *) 
  (* C_RSTRAM_B = "0" *) 
  (* C_RST_PRIORITY_A = "CE" *) 
  (* C_RST_PRIORITY_B = "CE" *) 
  (* C_SIM_COLLISION_CHECK = "ALL" *) 
  (* C_USE_BRAM_BLOCK = "0" *) 
  (* C_USE_BYTE_WEA = "0" *) 
  (* C_USE_BYTE_WEB = "0" *) 
  (* C_USE_DEFAULT_DATA = "1" *) 
  (* C_USE_ECC = "0" *) 
  (* C_USE_SOFTECC = "0" *) 
  (* C_USE_URAM = "0" *) 
  (* C_WEA_WIDTH = "1" *) 
  (* C_WEB_WIDTH = "1" *) 
  (* C_WRITE_DEPTH_A = "1024" *) 
  (* C_WRITE_DEPTH_B = "1024" *) 
  (* C_WRITE_MODE_A = "WRITE_FIRST" *) 
  (* C_WRITE_MODE_B = "WRITE_FIRST" *) 
  (* C_WRITE_WIDTH_A = "16" *) 
  (* C_WRITE_WIDTH_B = "16" *) 
  (* C_XDEVICEFAMILY = "zynq" *) 
  (* downgradeipidentifiedwarnings = "yes" *) 
  (* is_du_within_envelope = "true" *) 
  ramMem_blk_mem_gen_v8_4_9 U0
       (.addra(addra),
        .addrb({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .clka(clka),
        .clkb(1'b0),
        .dbiterr(NLW_U0_dbiterr_UNCONNECTED),
        .deepsleep(1'b0),
        .dina(dina),
        .dinb({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .douta(douta),
        .doutb(NLW_U0_doutb_UNCONNECTED[15:0]),
        .eccpipece(1'b0),
        .ena(1'b0),
        .enb(1'b0),
        .injectdbiterr(1'b0),
        .injectsbiterr(1'b0),
        .rdaddrecc(NLW_U0_rdaddrecc_UNCONNECTED[9:0]),
        .regcea(1'b1),
        .regceb(1'b1),
        .rsta(1'b0),
        .rsta_busy(NLW_U0_rsta_busy_UNCONNECTED),
        .rstb(1'b0),
        .rstb_busy(NLW_U0_rstb_busy_UNCONNECTED),
        .s_aclk(1'b0),
        .s_aresetn(1'b0),
        .s_axi_araddr({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arburst({1'b0,1'b0}),
        .s_axi_arid({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arlen({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arready(NLW_U0_s_axi_arready_UNCONNECTED),
        .s_axi_arsize({1'b0,1'b0,1'b0}),
        .s_axi_arvalid(1'b0),
        .s_axi_awaddr({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awburst({1'b0,1'b0}),
        .s_axi_awid({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awlen({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awready(NLW_U0_s_axi_awready_UNCONNECTED),
        .s_axi_awsize({1'b0,1'b0,1'b0}),
        .s_axi_awvalid(1'b0),
        .s_axi_bid(NLW_U0_s_axi_bid_UNCONNECTED[3:0]),
        .s_axi_bready(1'b0),
        .s_axi_bresp(NLW_U0_s_axi_bresp_UNCONNECTED[1:0]),
        .s_axi_bvalid(NLW_U0_s_axi_bvalid_UNCONNECTED),
        .s_axi_dbiterr(NLW_U0_s_axi_dbiterr_UNCONNECTED),
        .s_axi_injectdbiterr(1'b0),
        .s_axi_injectsbiterr(1'b0),
        .s_axi_rdaddrecc(NLW_U0_s_axi_rdaddrecc_UNCONNECTED[9:0]),
        .s_axi_rdata(NLW_U0_s_axi_rdata_UNCONNECTED[15:0]),
        .s_axi_rid(NLW_U0_s_axi_rid_UNCONNECTED[3:0]),
        .s_axi_rlast(NLW_U0_s_axi_rlast_UNCONNECTED),
        .s_axi_rready(1'b0),
        .s_axi_rresp(NLW_U0_s_axi_rresp_UNCONNECTED[1:0]),
        .s_axi_rvalid(NLW_U0_s_axi_rvalid_UNCONNECTED),
        .s_axi_sbiterr(NLW_U0_s_axi_sbiterr_UNCONNECTED),
        .s_axi_wdata({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_wlast(1'b0),
        .s_axi_wready(NLW_U0_s_axi_wready_UNCONNECTED),
        .s_axi_wstrb(1'b0),
        .s_axi_wvalid(1'b0),
        .sbiterr(NLW_U0_sbiterr_UNCONNECTED),
        .shutdown(1'b0),
        .sleep(1'b0),
        .wea(wea),
        .web(1'b0));
endmodule
`pragma protect begin_protected
`pragma protect version = 1
`pragma protect encrypt_agent = "XILINX"
`pragma protect encrypt_agent_info = "Xilinx Encryption Tool 2024.2"
`pragma protect key_keyowner="Synopsys", key_keyname="SNPS-VCS-RSA-2", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
FPXllyX2NFs/RMngGqZy2bLYbZr92CdofeZrJOHklWXExpaPgHNYp2Lzm4MnflbnrfSkCmLwwKT5
zfRgEip7FKQ5Zhb73p0MAIADixBZ/ZRt4hQkJL0T9brm0waLHfanjnov2aCX6jN3LbQc3ujmDga6
Dd73k78u4xjRTDv1/P4=

`pragma protect key_keyowner="Aldec", key_keyname="ALDEC15_001", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
kr7VKKvChFoiyRCReag+OvU3jnmG9pN0cv+BxhNmMKLthg/ksgNZyU3L+fQ7cmIQELtlUjwjkBAP
Jjq5RsCnHbJxj+Ys1GNhriiBsxLqxWCP8onhAVvgZN2xZFOih0UWpqlU8NVP8Eww1ohvkDgxTstC
3kDmYehxIUJjqCC/mgRZmuezqugrFdubYmBoz16tUvD17iA5qqCIMS9xSIXYp2LBNekmWEwrVqzu
R4koEo4UlXl/CEw0XY3QvMoHnlXgu6N/6sc+nxZtKSwjiMVvGnZE9UVvJPAC3Hn3zKFGlK53mmGO
Tj0dWzhwX0ahSYzkyJC/HLdbGZmriL2UNvDyFw==

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VELOCE-RSA", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
CaLc9FGt3AdRHfNtGAsGFY/QEvHY1Vv4TvvgCDsdDMqiuDeLizFJDJeskBWjeKDoE2cufK8TxiBq
mySRQNJoeOKnxTiDdf+Rx6m0iR6h/YeswegYwgghpM5KVrl6mSwF3+4yEovPM7a+9ArDQ5vl+WT8
SilNGzyW0KnTwe7+szs=

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VERIF-SIM-RSA-2", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
cEnudSW1X71p0Xuq6jrXOxHnBku87IA0RA3zKqmeZHZM0r+9rEm5MSzX8RecnQ994yiqeyxbIH2l
fGEzUzr0ZzryS3fkf2LnJuB39f2YARW9eVCSiaeWaraZuY1l89T+h3vgdlurS/1LIraYLS1MyOXa
6F1LAcQp3W4OO4ctc3q1FRMZGldRS1biMsKwJ8Lxj8NEOm67UfgFrJNQAxbVXEfbWRWhKtwNxcTB
JbgC8j4EHkIA46mzoHloeBAL6KieplQUBjKXSSTb66rxglbFhWLy+mirROHcocu9J4ZbvTRYZEww
4lso1lqAllVLAoKYqa3WImZuSRoTbGDngBt9Lg==

`pragma protect key_keyowner="Real Intent", key_keyname="RI-RSA-KEY-1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
rOyI+x4PlmKcVSFoN3oKgSYpVlmYxc194Ej04il/YmBg10xopy4zmtu5sdCP/uGSNYcNGWeAiw01
mNf98KyNgTUFXruHCA38qjhhEIvl4vfWWn3W3mFRxrIuwmnreT6qTvgMaxIkCdVBDP7Iy7O6WmCf
3Va5X5hnCHhtXgX5UYniBHiLjmupv63B8XMAYDH2n6mQ3H0DF7mtb7psBafd0Z6+IWUbmzwMtKrf
ZrRJBGAhNT0i1KrEjEh/rWjN7Z7N32zQ+Pl1kc5gYCQIX5McfdTdqSaRVXZ/HF90ymS7/8d5LDyj
Er+ORdcjnOn6oAyY4PuUUl4OYUHv5k+RglTe5Q==

`pragma protect key_keyowner="Xilinx", key_keyname="xilinxt_2023_11", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
bJa7kPSpDipzoJoQu1APEjc8vFLqBfQZK/grZvWijD7/FgMTerFCWLUY6n8DWeGdvjXvTeyrqCHE
2rP/H57wUqPC8tIJlGm6ZYQGjZ3TgYqLrJshDE5zYMTO//q0vuSraWvZP7A7SLuW6y7tFE/nplpx
L8gbYORx6j70okGUwnamCMS9yhFr7Z2QTJne1k4GNFGvy66URk3k5cBPl5j4/1yc4xGV+aWYl6L8
q8RorRU/CltObHKrji/jdiY1WtdGrkpRyCEFc+XNPazL9xSLLu5bz6XlvKwoks+8a5KYT/VFUovM
JbM0bpAXM8Z7rGaPuXjqXtZBg5praTZLu/WNcA==

`pragma protect key_keyowner="Metrics Technologies Inc.", key_keyname="DSim", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
PYKBDinOGc/kIVdFzXrz2wA4/QNFxLDrQfTWfR5TjYE6bm49vrZi0bawcr9HXp4OP1+XxPLB3oCP
oV5e/rYeDln531ebt8yEg27XCoSHEX4FU8oG8aBJ8fqgWayOnAMJt025WodOxuZXbhT1zPo7J3uh
6iO9Mv7RtYE2fZ1W+G8oN//FTOEJYPWlKYnt0cDeZrN3I4rHHptZHuu7l8T+df0PYea3x6U3Mvkl
ojZ+TwQtdu0NuYY5j3QNgx3+W2XYq1M773FAnEz/deW54EjE+jf1jjrBk2pl8SYxeKuutS15oPVF
eHdqXYVcJxoUY5JH8z04lITKEnZ4oq6sYS6dog==

`pragma protect key_keyowner="Atrenta", key_keyname="ATR-SG-RSA-1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=384)
`pragma protect key_block
tl+2vFCWZ583gQGsVC7oopz2NCKBiJ9uOHYBGzJZheOHJMqI/ehNvo25l710eBx00tztXzM30AH6
ZhAJg+kJwE2jO0MV5fmG5dnwXmLqoGEJMBs7xwWxvYK7w/0z9M0AJKD7HnuC+IiLhNU/fIxyuE+I
+vWqp//RcfY0tMMp2I2J1yEW6GUahS1ve/4JchssZ7Xu7VthoSDWXMQWATbvsUsDzeSo2+Ruz8Kq
Dc05HqEU8NgBxDPPEKLCcdKLp4byglwj7iCAtCjsPy8P18qjgb2sycFjNgmaiNMMB51WqeD+hneG
hLOue9bqVdEojkrb3q4WbsGZKz0bAGsryxslOlYHP1b8vey3yI2ixA80wyERe8d3GRIeZiSxGykH
qWxsE6x/iyi8QRb5mXZPMApA+Fln8tYmn7+1rFCm8gF4gJWhr1PsSJqTi658symGrzT0Ghjvf2QL
SvvoaeNdy0pOsWs7jLBFndd4GiFA+9K6Y33sziLToU9EvvFokENIslod

`pragma protect key_keyowner="Cadence Design Systems.", key_keyname="CDS_RSA_KEY_VER_1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
oYiCujFRj1F3wKsGZlHR9niEtR9MLXEVAVfy+f/3xrmpW6Ye5a+fBCvm4TH+iRQefGHNdMPnzTNW
K/pEPAS9uMJjOdFiu+APT+LYrSRnEg4W0dX5buSDGM6LBWAuMseoTMjbJJoYDGLRckJgW43E30mX
ej4823nkbfwc+Ecbrup825qLyv8RTQLNHafvJA5lSapdqXwnlOIYRmcHn+sfAh5pGv9kW9aokcdh
ObR2XYxX99rYloyvz3x0pmjxD5ILW4SQMB1IUEuuyqX6eb5IQ+kZ41hjvsHIuQH29vzpCfV9Jqha
WC5yxxK1R+cleZSKD1H1gVzbTei8uFs/91Bgeg==

`pragma protect key_keyowner="Synplicity", key_keyname="SYNP15_1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
urNc+S8AFPj+GVFdqJE5V7P8O6QI6MA3nkwYb8NKbYbVufnXKg6voJIRYYeYr7EOa8mrqirozWbY
Lln9SLWnkaAy2LvL/N6WahoQdCt++4RH+xe768XvSrVUFPrIwZRixqMLurc/tPov4i5P/ukZKl18
ZPZvXRzUNlvCZnMPcF+5QCQihqPbjcZ0YyGgWgX/ipTGG3sNqmylGN7qLa4Rgqu/mB5a2xVyu5Wc
911+/X3VVFx697WVaP5V0SbOzYN8R8+8B8kdznwixMA+f4lSbBXyRysVOSzYjo8bKEMqyKMVBQn9
xDmEuV0DvVWXdO7VPvWA1LuJFwS07OxeI2GCcQ==

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-PREC-RSA", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
QcP7fsLZxaDrG29e9HQeXfu2TsKsdyW7Yc1vWct6lbmDEfXkWMU1fFWSPIjPzRc9UOnfEu0bRn+B
D+8MWokqes3WF7txljBmgUPiNGZ8arUU6ENa/IY/Wv7iaB/ZKM5PtdnFAkjDIrYyKFCTz/U6Yzwi
hBGGarK/wYQOLzeeKRewiPTiNUL7tztWuMZ1t1msxD951EeKrwjrjcXIIuf/TzrOGUOlWgjHlnrl
4Q/lfMAnRLBNTSWG+5wWewCE8jK2X/gJ5AV4p3x1WP3+JglbxpP39l3pzedXqciZPbuz2XlFnRPV
KByaUaAShzJ56p8+0HjWebibqQdieGNPiPWW0Q==

`pragma protect data_method = "AES128-CBC"
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 18576)
`pragma protect data_block
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
`pragma protect end_protected
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;
    parameter GRES_WIDTH = 10000;
    parameter GRES_START = 10000;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    wire GRESTORE;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;
    reg GRESTORE_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;
    assign (strong1, weak0) GRESTORE = GRESTORE_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

    initial begin 
	GRESTORE_int = 1'b0;
	#(GRES_START);
	GRESTORE_int = 1'b1;
	#(GRES_WIDTH);
	GRESTORE_int = 1'b0;
    end

endmodule
`endif
