// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.2 (win64) Build 5239630 Fri Nov 08 22:35:27 MST 2024
// Date        : Thu Oct  9 15:50:08 2025
// Host        : DESKTOP-38PF9T6 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim -rename_top pcMem -prefix
//               pcMem_ pcMem_sim_netlist.v
// Design      : pcMem
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z010iclg400-1L
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
  (* C_EST_POWER_SUMMARY = "Estimated Power for IP     :     2.490899 mW" *) 
  (* C_FAMILY = "zynq" *) 
  (* C_HAS_AXI_ID = "0" *) 
  (* C_HAS_ENA = "0" *) 
  (* C_HAS_ENB = "0" *) 
  (* C_HAS_INJECTERR = "0" *) 
  (* C_HAS_MEM_OUTPUT_REGS_A = "1" *) 
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
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 26736)
`pragma protect data_block
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
P09Z
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
