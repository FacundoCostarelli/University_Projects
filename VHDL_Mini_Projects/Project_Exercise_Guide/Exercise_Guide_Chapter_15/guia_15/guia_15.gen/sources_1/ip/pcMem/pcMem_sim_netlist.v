// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.2 (win64) Build 5239630 Fri Nov 08 22:35:27 MST 2024
// Date        : Tue Jul 29 15:39:38 2025
// Host        : DESKTOP-38PF9T6 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim
//               c:/Users/Facun/Desktop/TD1_TPS_Locales/Exercise_Guide_Chapter_15/guia_15/guia_15.gen/sources_1/ip/pcMem/pcMem_sim_netlist.v
// Design      : pcMem
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z010clg400-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "pcMem,blk_mem_gen_v8_4_9,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_9,Vivado 2024.2" *) 
(* NotValidForBitStream *)
module pcMem
   (clka,
    addra,
    douta);
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA CLK" *) (* x_interface_mode = "slave BRAM_PORTA" *) (* x_interface_parameter = "XIL_INTERFACENAME BRAM_PORTA, MEM_ADDRESS_MODE BYTE_ADDRESS, MEM_SIZE 8192, MEM_WIDTH 32, MEM_ECC NONE, MASTER_TYPE OTHER, READ_LATENCY 1" *) input clka;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA ADDR" *) input [9:0]addra;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA DOUT" *) output [31:0]douta;

  wire [9:0]addra;
  wire clka;
  wire [31:0]douta;
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
  wire [31:0]NLW_U0_doutb_UNCONNECTED;
  wire [9:0]NLW_U0_rdaddrecc_UNCONNECTED;
  wire [3:0]NLW_U0_s_axi_bid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_bresp_UNCONNECTED;
  wire [9:0]NLW_U0_s_axi_rdaddrecc_UNCONNECTED;
  wire [31:0]NLW_U0_s_axi_rdata_UNCONNECTED;
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
  (* C_COUNT_18K_BRAM = "0" *) 
  (* C_COUNT_36K_BRAM = "1" *) 
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
  (* C_EST_POWER_SUMMARY = "Estimated Power for IP     :     2.622 mW" *) 
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
  (* C_INIT_FILE = "pcMem.mem" *) 
  (* C_INIT_FILE_NAME = "pcMem.mif" *) 
  (* C_INTERFACE_TYPE = "0" *) 
  (* C_LOAD_INIT_FILE = "1" *) 
  (* C_MEM_TYPE = "3" *) 
  (* C_MUX_PIPELINE_STAGES = "0" *) 
  (* C_PRIM_TYPE = "1" *) 
  (* C_READ_DEPTH_A = "1024" *) 
  (* C_READ_DEPTH_B = "1024" *) 
  (* C_READ_LATENCY_A = "1" *) 
  (* C_READ_LATENCY_B = "1" *) 
  (* C_READ_WIDTH_A = "32" *) 
  (* C_READ_WIDTH_B = "32" *) 
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
  (* C_WRITE_WIDTH_A = "32" *) 
  (* C_WRITE_WIDTH_B = "32" *) 
  (* C_XDEVICEFAMILY = "zynq" *) 
  (* downgradeipidentifiedwarnings = "yes" *) 
  (* is_du_within_envelope = "true" *) 
  pcMem_blk_mem_gen_v8_4_9 U0
       (.addra(addra),
        .addrb({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .clka(clka),
        .clkb(1'b0),
        .dbiterr(NLW_U0_dbiterr_UNCONNECTED),
        .deepsleep(1'b0),
        .dina({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .dinb({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .douta(douta),
        .doutb(NLW_U0_doutb_UNCONNECTED[31:0]),
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
        .s_axi_rdata(NLW_U0_s_axi_rdata_UNCONNECTED[31:0]),
        .s_axi_rid(NLW_U0_s_axi_rid_UNCONNECTED[3:0]),
        .s_axi_rlast(NLW_U0_s_axi_rlast_UNCONNECTED),
        .s_axi_rready(1'b0),
        .s_axi_rresp(NLW_U0_s_axi_rresp_UNCONNECTED[1:0]),
        .s_axi_rvalid(NLW_U0_s_axi_rvalid_UNCONNECTED),
        .s_axi_sbiterr(NLW_U0_s_axi_sbiterr_UNCONNECTED),
        .s_axi_wdata({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_wlast(1'b0),
        .s_axi_wready(NLW_U0_s_axi_wready_UNCONNECTED),
        .s_axi_wstrb(1'b0),
        .s_axi_wvalid(1'b0),
        .sbiterr(NLW_U0_sbiterr_UNCONNECTED),
        .shutdown(1'b0),
        .sleep(1'b0),
        .wea(1'b0),
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
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 27024)
`pragma protect data_block
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
HfIFvIEj
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
