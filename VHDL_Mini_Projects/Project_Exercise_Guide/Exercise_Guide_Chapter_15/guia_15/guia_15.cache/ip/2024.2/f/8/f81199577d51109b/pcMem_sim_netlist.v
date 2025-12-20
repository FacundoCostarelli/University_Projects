// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.2 (win64) Build 5239630 Fri Nov 08 22:35:27 MST 2024
// Date        : Tue Jul 29 15:39:36 2025
// Host        : DESKTOP-38PF9T6 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ pcMem_sim_netlist.v
// Design      : pcMem
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z010clg400-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "pcMem,blk_mem_gen_v8_4_9,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_9,Vivado 2024.2" *) 
(* NotValidForBitStream *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix
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
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_v8_4_9 U0
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
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 27136)
`pragma protect data_block
1cAt+KHn11LXuic8zzrMANKuA9ks9w2RVFVsGR5RPyDmXMQKUaYSZpxVvieaxg/wS6YvRn1uecco
dPf2W1HoNMWU306rhUf2Ba3SYPdq8P6t8R9b3MNRlk3pxf25yxbC9/834rTYqk1fRD7Y6wn2XR+4
lHcmwBJnhiqKSuzmTLqb5hJ9gFmlAS+UfrOG0icd5btBLsR7W9Ce2xgdF/p7zfW97YO5MmjEeE3I
tyeMyiuWWmAf3MiX6rsqBsc8i9W3M0iyoxIamSsHGT4KS0vj7/BBOQ/wgLj92V/5dNAKQ3NyqBFJ
d1acNyuifQgoyohoSLrLHiCLCESjyoTa/hs5v5nzFpwnC5HW6bt9gEQo2XdmJqDjPSiIWvAglv4w
ulAIRcUZMoI5p7I2R6g4mxwxsqBAOJ3lvzq8MdIZH4GnBr4OVMxk7N86WmDguGZlNWZUSccmmohd
HLJMsWbJViVtmEFbG5ZmeNIgucKbQQmvXf9N6URdj18YF1jRKmnNQKE2ljMnQr9kt8VMz/e81x9X
bBxUN8DjLmYHsPL81nuHuRwBNk5PZEGF161EJKIjiiV4Pm6K2PMKnZJq6ypBkV8AiZ/vaXvaW+fQ
UlJxpITiz3U1EefsdjRkpDZaRfd5GewJSAfMiVSmICxrBLFkHTLvzdk9YGEtz5bmGVoiVpuucgKQ
QyCYujNDXnLYn3XhYKD9uzxamlsaLrVcAMd2bw+X3ZZZO1ZgCcl06PGAhq2BcGpmPbdPaQ9tvZ0J
t5obh4rk7fhkD161B+5AOB+d3qxrVBjhQvjKDHdFae1zxPKrzOc04jj+fHs99/Du3JUb0Of3mrVl
GY6QkhUhZ2j+D5YnblJ4up4hjIxkfyztQvMhvj1JmsuMLlHQ0JclJXa9SwJzgN5gr34Q9e/GS8A5
j5dzV3ZCHQ+/8GgiDqLF0EabSxHHBQKgFZGXeFnVkBeID2qckV33watm1CZZyDPj72sDFv9F+ULZ
VbrkuBRTe6cGbRbpkU0NSq76NDoisHEOmYLB7fbzFGoe3veEG7Fcp4wUhq1ZfmljQwsKXTq7yX2/
63yEwMdxqhrjHUsxw+DMlQwWSnIxgebq5O545ElMWebRJKkn1Zos1d0gnoPkrvMlOCnEaYFb/VV/
OyQaOXwd+X0p2pNzpRrLeURUFfoXCr8r15TuYsEX8WPlAdNGZD4iaol151A1RjLieMMylh7twZGt
s5vTJwemhKJAcAG0+VCxmJnwhX1VCRD7WAoIBKSxTFkCwvGR1aE96pz3mrDAZpIMidpUwT7+RHXN
YwRqSVf16zE7iPKCHkZjFKOPLLRJioR3EhY9fkmUBEAaYnsQdms0xMBVehnvnVpBdwSEMmEtPBxM
bA/nARYPA1Poolu+NH3cPLq8nqu1mYrdvyEIIiTFpVT+o2PmveRus18gLrwsSsUp1ud1DApmSz0F
jLgCQUa9NEfbZVUtra5Z356Iv4j0XHkrM2H/L/PHQBUUngfhG7klhEMn4WMJXEI7olbS5pmu6kLx
Y8K92ouuILUO8NzRPJGQXAczsqNvSf6EE5nVE4DsOa4LSnrrxQMCCDyO8ZBtHIL4cKMn3wLt2iYG
ImL2gmVd4yzpHj1VmA0XL8hgiNE/uwRp7TLHrb4E6c3nY7v8NIDQFUzZVG9SCs0D7ZjPm6ETg5jO
kLyRKqgrZN1VpQSOMGmfkEqoD6AF0wge6+djaqVdgqrrlNHkv2c8GZHQUHYORm33CPx+ztVR3ScG
gGEZrKL8RnQboixlTBXV8TH6Na5n12T1JMvNi3BfR+UePhTNESBSCcSZC6lDVq2mINS3r+pV6CUa
PWTqn/cSW0hZdjQbCU63siTCtQapKA+VTldfC9/a3p2zn8MVk+zqq1jD+BODBEUewEW1ZLk4YV34
t0vTXOVclng336RuwIidHztAO8M60P1F59UWYDQ7g2tt3QKRI19H7pog+qCUASNgIKjkBKqlHY96
912lFKy5cU/Ypj8tus6aX0D1FnBye/YIXdb11TqY5lho36es+XWuTtNiytgIiZPRPtxNhXa95Pym
Wm2in8tMrkLlx1BBa3gt9knkY97mJVRRvdphFSZun7GQkyTIXdgTer6dsEY8uJtw9Io7cnodi44l
UDmRB8iOTDboo3PFtDSbTiKY9EFG7Nrzs8cBwVRhTUCFFKpJEl9MbWkZWFWCL+ZMOM4alkgw98fx
xClEPvEaVLBw8oR6KrKeP4/eb86E+Q266hmh2NnCHNWDaEejZPgnC9V4dixMhh/w+0N5TvgCcAOf
nS6I5HMdEpGuOQ+KcMIbKOz82zHwMfC9QM09AFSPLYKkNj5REHkvXHp8XQWQrtvVsi+9625WedHA
aRUF/wizFENZqP3bY44tmITRopB5XBNllWNw0/aFjKB023EBQrVB1iC3aauwA9jOejMbnxVEYXG4
m8rsU9Ys8GgliYdTzgKVSrK2ekqrq2lWUFm399zetYa8knVQayFZp6H+QNVg3nyJG+n5katXr3j6
2coj76Y5Bh5AzS1KrPjCdixdN/rgggnztBU1LowW46yFrn6Y4tQSG3hIZ4DX0GjcP0w+zTpc5+81
M7oSVyt0hEWdACMkZsyN9z+2Z5Cgmb11Af66qc5UhJl8/bp/fPHiQwoKm2OmWazzBeG1FD2LA2sO
j1EsMNHCi51faOzOGYYdq5/CmlQceHrV3LS+46lNwEEQV56gmDLbDa++uxErHw6vTFVlsNi9U+8b
UaEzWoQ1wRYOMMUU2M0XO0REiDJC2O9VuDwIzyWFovz1NO+zXZdtB0q6VvrGCtLvVlpCueUxxe1L
lWoEJxmJ3AvbR1tXJ7tHJykiEtIuH3P8ttUvNF1tBP25rB8AABk4TATcCEMcpLxeJwqmnckpthKd
a5enfAH7WVle6jaUOZOzmh60VgLm6npIt4eriwtz7EVT+0YFiRy6QGopFwQTX626gSRWdnz9on1I
2dj2wvK7UK0BrkvAXIdbVbKQin9rhCyzOq69Oto181KrdIMwms+eEONFu0c0ueETPK4BHLCxq8rK
cvARDPEE6NBROSiVlP3uGhNjjXBnuniAHm/PlUhro5Q4vYnhz6XrKIk7/noHLptpMCsjrGwNPNr8
25bkEQJOHo3BBiWahxM/Ym9W2uGJpJ1V7Pl7qX9F+OvD7PhNMkOjN/Cuj55bwW3lLS2Mzq/Lj/aW
2l2+pHeTPL/7WqSjvjcCyvHGAbcJRYtY2ppGD8QFz8DEXDHHVM5gioG5ATmEj3mihV27TeSJ04ln
3djhoFxwimahdfvTukTtOs/gQiqbIEcRe4xKJdg8RUt6I8pJwKuydq6BzlVdsllFUU6Il2AHoxR4
GCUlaY4Bd3M5VYwMPZ/Z+xnopFjXgei0yCJslZQvTqxrwngS9yGr9+sShOR4G0q/fo1EZlj0ncJY
soqwjg6kzIUpIXvHPZDk502huBg4+SmounB6/guGBRXh9Xi2FP//BJw4MayzJze9ACwOgJe10gWM
3CA8hiEoIft6Jk2C6rV44hTDVF2+L6wkVyzj2kJ5ohUkl9mKOPoZMalq95isfBq96fLDc32j0Ow5
ZcgB73Hkx2lvO7ikC+Q0ZIrUu9lgSDQBLnsANPO2OUZeU4Ies/qu6uOLN3XuixvawxL73WYyymto
wLcD2KoU2EmLOtiFBR+fMg1Uu9LlJqBFte1ZQqGC6Ff0dIonr3fc5d6Q+ekt7O1mDAmBpoqESSJG
dLOZBKcY0nNxlORBcQzV/bjfj2QsPVeeYk1N66fYVypZ/CSFFUrvAOABOH++FJBOrICli38amCYh
EMKfgLvEfSFSrwGYr0OHYYNecZ1Ktc4D/AifAnR/HKQr/5vOvCAFWvUDz9IcbqLkbPnamalwkE+a
0j/sQsaGbceRhCJlcOnL4yHJI/B1AeP2BrWCdToQTMywARJnMOpPZRTCp2yvW3bOjAF3tuuGVvyJ
yJeVhYrSgdw7U0obHp2sLXI5ZKmAxUaqsR/40BPiNjh8OPsJZrJ5fZXraaN+pi2wwZXMEzL04OL0
icKaOTm6GMvlei9t+X8lWVYnd9GQ4pKTA/ufnfVr6sL5A0KpmS8v/QMzEl7kA5kNbIJlPkhqmgFc
k/LqQjWA4Ng3dz+cram6StzUn8eFdQYmEvAWPKvFVwDQWlayTJ7nBij7oRF9X+Fz17wASYWs+bBU
0WBPpOlcuBnQ/d94tZ3jHPlaV4jvZzqGCNQknFbp7QyfuzdLDlxrwYm9jxz3FBVHge2z+K86/EOg
XLg6ldNcN+w5sbCMa+vPZz8c6nv0pSz8o6nLqdiaH5HM3RJqcvHIzf34w8KVxsNvOAw5DRlZRgUu
YaclTdz7PEaJRqXCbWGCUag5eikQkXHtZ+fu6BqOrhAbSdheJZ2KEI2w1/zmB3L7jIg1qgomdHpA
HOgPUeExHHNmG6HbYbP6XmA4b39cNv4l3Hh3S9OO+znOtMIfsXbbgZsAY5NaFp+L9Vyuz1qzDjy3
2ekAhYnM1FzJmX5vAPEbYrIPnbT8a2EJmZNOUTGsejZBTxHNZ5fFg+vxlSzWLaRouYYqW08W5Xf8
+t2gPmcLpOfDE0RFqL/HWaLAhCUwOcuTZoBLVslkvZg4T9xhsL2Y/WfUamS3XExHQQ0cs2dt0hkI
Ui7Kj2Z//at2h4xWJhexpxDbl4kSDr6eLEMNvRrRIoyWrSdrcvymXt1W5WBiBSPLpacLiipi1Ynn
ln1PrVXkeW68EzBH5A7RY5iGlmt3heFC+mpSXkS/aAyvcailv6MTdqXIl8lJBh2sFNsHd9B/Fclj
tpkBPwKlw1Y+OGBYQ6PExSpw/dB4aVbAGLFeURh7f2TXZLEO1xfVk8Vqbp5UHeUXPgKH683RmXdh
fvdAeyJOpaD/wUy3LpgWW5fqCK1EqEFl7mIG1B03EF4c44Lg2eDGN58FqiFKTZ62UPjyB7lE1hwv
9y1ePk4v7o1BOBgjz/a2yPbdPt6Vcw16CmdDs3e8eqn0Z4v10jaHFBoEGAtBcWXuDU8tjOw37stz
zKlQdjp0InQkZ/ewQjK/8qOWaY6FLXgnJsQIaLyk8KyTThAMiScYA50AEWkhg+hi8b5Adnbn6tFj
+OKrNh5bamUfRY92UcfMH2brwD5+MzvkoR7y1DS1CF0UHjjFolmTG9VOVo9Tq5X0KHfyll/fi+af
93qantaq604Uko0R62hlk26N2XyU1FC+d/dkzytUrQ0utiWq5csTIicL8lYq4e4wn8ob6qQuuVLp
a7Bfw04hCpwm4BlZi2fWV7r9JpsbAd/ceagB6fPhKCoBY7fJVXAcDOlctEYu5SWsDR1bmkRSzcIk
pun1zWOjbItmT6FaOEmuZc9mt3C0LCyJFUovawsSU4zaT8nBAWpBx13iGUgZ5Lh6c5CL1sO4sxXJ
CrL9jFitzyiHK4jxkurezT7TKKUoIiZa4AcluS2u+K45x9shDyVI921jr6hGm3deRDv/snSDUBel
4tKlZBhKcIgLgaPzMi6uZAjFfr0d0LwDKxanGOavd33uzxiJchUNqyf+x7Xe3haqge3s7NaPTGp7
mLzIstE9KeQVgrwaZNs2fdwwhIOSvW4kR7dUHLC6AcPNAyO2OwPeo4I+AW90X9LZDHfuBqyCRq3g
xEDCs9EKNWFWtBT3qtJcc1ViTrTHtTfPoeoF9mqPJPZsJz6lGh+XCK1stkfeAMGtOVsmOdiuipx/
F25HaPumf8hX5Y/KiMsaOO3xFpf8WhvfQXQiCxFqAvNtJkXt8yLvliGViK6YuL4yCOTfdDl4Oube
kSYiKphPLu+rR3/PrsXGcJbpGEu4e3aVr2PobmM4zFa21rppjn31F5+EaS1lB7jlV9u7oYCAUVaX
gL4BaEe8FVxM47Qg+Bbj413mSvSYn6oGboPmL7bT7+5kP1Xh6oIWp2JH3aitpwLkblOTRoe/Ix3B
RS1CsSHgpqTWGBqwikFfQddsyPmCq32DE1y4wxhlicl2mhRA62nNYitb1C5bYJSnbly8yG0J8xzz
9qtIm8ZwhhywsmZX9+3CHw/UZtK6ZnRDM2z/DwLmG7j9kUtInLBzji7TR0ZTctVtq4g6VlTvHeIT
EEkdklAVfn1GjDoNhN/QWHaVoZJI6tGMkaGYV3l1yeQzi8yUekEJcJxgM4BA1565/hM/lX/FbTLp
/p7l3USs0g7jeYZMfmtJj5GaOaTUcuGQyOCTtc3E39Vgb8QDV+Ml72MIw48za2AY9ZQiJTA1CVRC
l97y3Wm/3hPxbXpKsVVxETRH6PVvAUCmunboMCIzwsGEhKBO2FwHqKx+GxReI3rko7ogp81H8+HP
BZ5afmSt4peqtdIBIe2z89exQYxTUZfrrMmArRuTfTuRqeGRbtxyJDHlUOQZvdoSd4MCUJqiZ0LA
YAaSbqkaTonimMPo4767ncWuldMQFbyXjsJmoQBPqFLbmUFr0IWdtC8raOIcwd8ZiMWrMPNBA9dv
CE1gzCwaOhAgwDUz66qaEIMVnuQ5Il5m0zjEaVaj8+cdUuBxwCJAhYtMgithJ0Alg5iKQum2gsyj
Xz/v8YWU68H1m072+d7b2+cgBH8/Wzbk/+oTeig2kFXfJUohQeC2sI4Xu7PCgfSypWnpMoPgbGmX
apiwXPwM/Bs1ThGrAsvCLNJoTK2nJxOy8uDBeIYqU06zd5CIA0SUQ85TupU0mPMzLjmIXW+syQYL
DFoVqwUZ8WAyph5RO9LrjybpzV/11bGOqJWLY/nFgevPjxbmmtjUpom24bpXB0C3gGIsAhPu9rq2
QQO0cztE9ioDn6inkqkWa/DS+qZu806f/nO6vlpDq/eF5OSyrnkOripUgV1GL5kYFvpE7akVn9yE
Xj5XYTIkkju42sLB/dZOldPTTRnY6ZzPtU39c1nYqgJkedbb+cuJMIUBOp+w3aFcZMv7l9hrxWMV
K9p+et721OlTSinc+I6SBWmQgw5fqeXYEfZqKyANA+UGWMRGudz5bglfI1AIqnOvkHkoaKlp9oUS
uTgKy5Do6+/HOVXlz83wz/fqxJkPD/q/ocAqqvV3vaoJE7AbqT7ZpuLQ+6LnX/E6scX0vTyGEUpS
pYgOoPYANnTQyccDdN2Vo1bKR2zMHrxZ28IwHdQ+oB71yppoZDOS4YE/K37MQAphaiSu+wBVW9dK
6mU+ncDiSkxF8y4pn0YB3ykCm/72j3LORStR/LbwTMErDk1m30tqkt4KZO++vulLqlg/iIrkyTqS
FPor8kL0mkatYcQMkwDvH/drtNZAZhxmUm9y1X6/VDteYDb3Gr1lbTZmfuWz6GtzlEo7F+uEX3XO
M7sQXVYkW7wKwcRdhU1/1V/udAarquTbv3FRw2v6e2uExMMM3bENVPw7Pcvh7PxY2k78K9//scqm
f9kpZ4ax6ecwATsv0kMnFf4NHaJ7pM8AldYnNGj3JwFbF1VLwz6S1aYdEzjPHh1eBAQ2frjSlzC6
GplDIhbxHZLpnY9G7nxZn0SEhWqQSq6V4h+2+X8eUcnAbkO6B+vsreKAj4t3rfrwbSElqJp4DK4f
cM8TfDEkk6uNlXIPWs975Z3yy5RD5DAlxpF1N1J+tP/LHG8+s2zI30YmA425F5mfFCAduwYzhPp5
OOT1C47ObVKJytBZnSMf/d/Fn+3ZibZ2Aqp08/10p2l9xl+R1erwxntOI5kE6bN/MSkjpCMa/Q/h
Ris0CQl01j73W3I1LBDCdsTlx1jj+EEsHJv12p47+Seq8SZVWaIQe11r4AV+k+boQoylwuMpoPoX
Gm/AKC/Z2eHWBOWXV0XcYxTrrUoK2PmO3AlPaghQ8KaPITtJ7UvdUx3MgRD1xGKgEnOP/g7WBWsu
jt8hDgg7zFNTUoasTgn+XSdFcq2NWAnH1hor3j5AZ15s19SJnWNcPHvAG4cbucolsPEbA77xSOeT
wKa6c7xlzRI7aVxNmF3N6f31xUeeb85UnCuGricKQOr1ngXk917KFYBo7Eo0D1VVzZ71mPN90QDK
r4EyF+FiJfnATrC/CBfQlkyxyDxnTgKtrlLhXz7BXyMs83Xzx7nHdcg2/vkekj9/7m/MqJl+u80L
MMfrX4z3hsyFyGqKQUK6RDmQBfe0zcI2uUhGMoPwgb2rn+aaE/W0upWG706Pd2sMoujvg0lyzPKZ
bBApWVXCFcaOIJUaGxsM6g8A4ShOAufyB7au6a5eWKmx+391II1Ewq5fqNcoVJAsCoubAUT22A32
805hnGvwshGw2AQqCBsfnopsa7q7kzcf/tg7oaVS22KKp/8DPKBDD9gbnvLCtFvp5F274aiPFbXW
LV1/y4BbJ+fx0oOik2uxMuegZdI4N4zf0f4TP8KV80ItjdDFNqNnnfSPkxP0aCwh/mNqgpbfeLlG
xF2BcD1nsiOs07zeMzYG4abMDpFUOg7aySHyO3hcobKW2Anl8mj4kot38GJngUo8rbYpkQpuhir1
IK/vSFdQ8uAyaguw0lpxC3hQ6TkGBmq9vtNv2jP9xyBhM4KwmGyeXfiZsdabHJaJT5PeFsBvLhEW
Bkw0pibY+wyVZWK4ll+Yt1+2ZwubjHTTT6a08rnARSBjSqKyNLgRuaPtzkkR6w+Barz/CsdbSUPd
9DNuRFjVig27afB89y63513L0qudaAYxci2fihGqyT89T1UlMOcpWeICwd6RUcfxscLAZaeGIZ7Z
su8K9qh649ykamig9QbPHoi+f6rT+RUHDMhFY9AC1YBRy+0N9G+shNns6332UViHJ4bkaXTAxUeT
STPCT2T2esRyg5Pp12ndppCyIgQh0UQPO2Y1ApcLId/3FMOeaEL6xZjkwsDrNtRMgtZASJ4+ev7g
/tClRgBSW5SlUpWMC8kSycPoawKAJcSpr0p9Jylh++/2I0LAZOoi0h89nyir6Nn90Al91SUezq/E
f6koB9g43ESXrOBkHinbj0BI9/Bv1G72M+KSzILApBIt9kBQajfUt8awHrorhTqV3bHBvBq3zVsk
+MjK3orIYec1zpZjTCSh0v9lwvblTj6CndE3gvvxDHE9ryXMOQlV/QoHKNGU3TngtwwXGw7gv3Yh
pYCUZxgCVNtOFBgh4qw5uMVK1Vr1KRKoQXUCa4l1VptMkb093G59v/otoO8vE9+n8MTJ1iekQZ3c
cG0GQtm8ILBMlNU9gtA1ghkP+KUV9MktA+Z/Y5nIw1EXt1DtPQkDUJtnRbZ+XNGaHeV2EnkG5OPe
orFFwsF8ZYR5BSGnU84h8zms0ddWehXOeEJuy1t1FJBbCH64/mZfJtwn1sJso+a/m9G/+cWuLRWA
SbFfVhnPMNoL4oP0iCbwSkQldsQlE2ccvTBL9DBVEY6wObP+axXsVHKJkVqW/lHIuvT4CNcq7ZCc
PrZb61X0hLnaCP424tWKvQ6v7ag688bcVhEeuJmI6DrOkOTanTF4E90Qq4OmajEVzs46mbjzOtYA
dLQsY/WTddBfh3Jj3XnARKRPsvQlMw/lrr3WPX0uWTG6tJtvohGrAGB2mp7UpiPUL8fiO5+SaKUf
r8wHomp0PL+Ng3emR+GwpjMwqFwWzfM3mutXM44tsHVbKOxiuywXy+eS66FojcdYcFUoVJdpfKhd
dYb78t+rhigOiV68m41fT5nTwiFDxibw3kw/S3JMU1IZxmHpvKrI1Ctk3NJ2UFsdRQf9RoVjRXaE
ekEMfAWf/wPWI7UK3qCkKpbwiP1N4EDx3yo5yvq8BqTOwjjnq+w9U6BsIsTJe/clwHd8diGX94YU
HgDUnZKsLOMq/onH2sIFmSXb7FgqyiivVguYd9N/j/DdwfwtCYrkmaS3ViaDIFAX2ZNu2iWdsYsU
hz8haPi0heFOlSREzcZXN5CB/JiMZ3++mVMm1wUCBtb+wgEbYbkW7BbSHQbdpgdmwaPCN8r4K/Oh
+x81Vo8trMzPoW+QTg/TnqJdq/z1uCXouJndHI1EMlBfUBJ5XbjZ6/bvi1mgW8+E/GfySsOM9tuz
Qz354q2qUNTN7j/hmUD2MJ5RjfIZZYTjVY/zYcjKByfiwMsizMvquZEfyd+WdC1miWEqjRcjmglG
o7zTsEYpoGstAhTxeB70NjqwrcgiezZ0oXLVv770SOo2BT76rsnFqu/8+LlDadGHiUcIElYo02az
t3a0DZ/M1O8I32T2IwmbTAF7IpBrgxckXFGPfB6hzJPrSDa2hLKaDARBMycRz8q7IAQyI1E8eL0g
8kizSLVp5kkOEw5A2vvGow4lVO8rtWZiA+Wwl1zyatOp4r5rbssmpZJ7Jec8PypLtUdEjMXd/xHf
UOnfTwVyg2tT3xMsbPJ8ghXGYLFe6XuEElUz6GhUIdA5HDQpORFP1ZJR5fvHk7eC00928T9avJLH
LfOKlV3u/MX9OKQSD7gVv159iS/OXvnkuiNJXpT2SrQtpfvda59h2FdfC1+3WEobVLqH7VJASYjQ
aIQeb+Y5cLsELF65wgA327HVtrPZRjOcGwrAtEBQ94cuXDkFavqk6U1nfcp8TMtojV2GzJXchqba
IKX+7ryAcE2ck9gW4rkv9X3r4rsY7WPClHAWJxsEhdAzAohwNgmmfIKRL6ZwQTwgcEF1VWdb3rtR
c+hv3dpyapeEmnBt5MKZKkgzW+hVhDeaGdC1lZshgZC7nB/0MoBPfVlUhUa6sQUyOr3xrTQS9BIf
Wxq5ygfCA0Oug7xMeCRxHo8IRphxIuacZ3lk7NSVjvEcVjNO9ExFTZX9FeGxiA3KmKmTYqcF5Zbx
TlT1XckhXm7wNSb4b0E5fymwfssBHoLKStOn8/c8NIq/ebsiHyLACbIyWX9lpGCyFv2h3NQAzpUR
yxBpYVwW1eHJ84VOrp0dpK82PJ49Mnuo6Ko3aIdGlrqFXYTOhVfJw94koAGJKaO/dmxVGGHX4o+1
ZdlmAmj1g2gk7HwugGcq744K1IAQubl6Jp2DBFQdBx6uadOZ7j9/AMJ0ikMnkjiN9NetU0+AqCb3
tHzpHgdVX8I3MHf72XPDS3oYQ+tg/f0ea9rO/oonXHyfsT9V7WYbzVKKispSRbCuJGTi7tXb667H
kYgx+OaAQZ88hpoMceJPUgUuyGtBt1peL4rc6OFVRloYZlBeO4kodQdK5G+zUwgxEmkdDps5wObh
Wav7wuArisnOgM/SZufgBEjoKrq/NrA719XihZl8G8jk/lSgerXaYM+rXkKJUxHspt6VxlVjanqa
DTTiI1qEMto+VUXIbPdPzTK2/H9HehjRLHv/g3DNp8BAQ+0K8kt8DMxan4aGk9e4QWG7m0cg+C+h
BBcyr6VFaEkhiQppL6P6lPSWniUYR1Z2oa7yQfq2KDuKiEk0n8Eklm2GvC2cVXUnR2LQtix5LBze
ID5aLv/2I0e67pJdu8kfDiYxMQFkhIKl2tzXe/0k+uX3j2OuUJWn9K7vab9yipejTqwMOXuue05I
J9KUBnU8kQzXwHAd2VvdKJ4XY4lF4Wa4EC1sZdyUJHSe+D1LtYUwerPQ+1aMD7iAsZGmYh6Ch6pS
Crsfxse7dTzjn9l+4uaOnP0lAXQcFtvBjQ4HCMnktZwHTeRJXzFil/kNOHdw0Tu2k/Nt9jGKO/G8
7/33xMOMGlnUp+dLPa+V0MK5sCYibXr86mND2h3Eq/TpjjWn/P4EXEgyIHniSToweKGuGOmkhqhO
VNUZwvwVhPL1pV7BfwOuyfdRljPei97S71JiNP5usddQA9/h5P9MKPQobgt57vkYdj8GMIejCY2e
6r24YKSWVV1XBofU4wVAWnp+ANFOKqUxLvu1T4ENQq3mHHzcPo99OHiSg+9BHYTEVAUvh2S9miS6
3ghW4q1E5H3F6qg8DbAiEZJtgN0a4lyK3JPJg+eoELLxaiqYQUUn+qf85sfJ9QSVoUqHlEUBEZj6
06NJjC5FcKH63YJF8LrU9veKhIe+vHO1T5ki5140v6C/cCVs3H6AmNa4PzL95n6Z476uQpx7FQhO
vAHfV9VGwctAgMfgir63Edym6/y8cP89Wp5cAB5Bp+b5LbtGfIW3zCszWzbdViNNVzrbCVJEUGEa
zzNykp6j2H+Xznr63kTfM2Jb++BRqOclBCIoZJatTb+gf444FvO/ztqdrWJzdTX+Zs0/ZYjlwzBB
WhX1SXhM+rv6uINxvrLp2bnNi0kuQSEO9q/s8Xxfs/NSwS1uyV5QAaUYV4QQTSgoeLhVgTvitLqG
Gg/B2+HveY+5l22PwjYZryN2olVsuEC1PFvTwNOubyDdb4YQb3JoC+i4drMnxlAnattHmrH2sP2O
mrYSfdfUdB/99CoeJTun8knIX3Uq5k9AP/9YbILXTiZ197GG728gHSAeJqT/LCHL9RING9FBxb7Y
Gs2WRceOXKN/V5CiISrSC8u4ouD9RwswaI2x080GxlbWK7uAs7duby2uDBFnM84dwJSeh1WO4Md2
Ic1+gGxxzhGFM3D23zOYs2z0KwWS1LPHJ/A7IfhA25Lna8YTVgcXtqMUdLKe7NKV9BrR4JtV820S
2oZTHRULTKj87doFPAXbw+T99i8kKnh/kL7RpCo9amDKNuXC5dQDE36lEAxKAR14Oyy8KgmBE0cm
M0Jk9HinkAbXbkWvUekO+ONbNyPMoES8OUdwk4Rp0aP9ZSUSOw2zam7XSL4FJyXbeHq9vFzBEFUY
RhgLHPIqiHvJY7qiP/r+2Nh1/m+cmB/h6S0JNHizeJd4knCvwTTTKi0YJwFu4q7zUQ8JsW5+abUm
rXmw+jye5ss/p87Bq1IMJaKQMzCKakzDaxus4UQwtzibGdjFbpNZXcWSCyY0e2txh0Eiy/NqMP/R
rV7nc4AKcPgj/h5DqTUjhuAqO4/U1/UqVl0vlOhhPMPba6EdY6Ns7/SdIVukZUIfpxDnDhy9Tp5a
F80hvhefFlJ/ST9tLfwPyD5adyBqgEQaBbJeW9zc7Tdfm4GoNGyg+L+V+fbXBmZXfGY+IJMA9uge
QgHHUDL4re+arCTZHn8MMfi05AFXZNUQLVZ5zz9zYrgqtR5ljYctQ0ENnQoeYi8mwXf4cUrdvHab
bLqffDTm1IDz6H82fKpIO82I7P7P20YJj2IVgVAjSqg6SQ0cPIwOZtcTtlzbD/7P397QcuVmmkDG
ulOy+4Sxo0jNGEmHU8tTH4Xlp5t10IyI3rLhXyQerbIhr7V9sCG4XGOW3r95ewlNiR63IRsdsE3e
6de+v9U4AmGRc37dHiH2e9UEj9c/HBgCaYXJ/jS5ucQW0hngG/GiEUGtMGYPxJQt+GR4FQ7b+dNp
0XeV8fwxnKyjhaPd4Rz50RcXgqzrHm8r9Nu7Hy6LoPK0v+zustDJtVDdVoZKATAi8gC3YBGN0PfF
fh4Rm2vUNSlStOCmz0+QBKk0yrLOHsReczuCVlvBPFW9dGxtKZfT5sOA3v/GZ9ezHxxxLRDYWJqj
XU7cFxuYk6daiOBf1lRYPtElu9p+Wyn8IXMCkoEYQrclDPYlSCr4VyJUXfYQtDtOGIu1HtPW8HIk
0t7YUBYydo+qA3KOjIfBBxlRD6PQlPYH5QY+FDtuh/2oljAelHKfp8dsxE6IOTsKJgNwQN6SSyTg
7bNVwMVBCFIZpSjuLIHIIeaOOshkmolnhJWGu3NcwtxWarku0KSfXb0Hzw9thuaTttr2gS4T9JML
wLgW203qTxDs+W9zjFFqCriAKGp6TAoDJtOX5bNJ4SKIZIEtyT25gb9/FQ7CeldP+sYr58SX53bS
5CXkrRpyqEdtbhERh14FyDe87oD/UoqCC2WzQRVd09lgh6rNxR30iP2UW+nY+iKXlhtK6d9I4pwb
eL1RVGZFuKUolIAABeM6U7CBwn/gUVDb5dw+8/PMMa7j991TeSPnBE9dGxPdW85Mmqxytwzbk8KF
pSB2YQw4cGUuBqgeso25tH+RhAX07hCnaaHUMJReMzvPgbugd6bAdyhBUQojEQwjxFTABRLkkYPJ
unoPkPBhtItM6Kshq5wngXAf5BLVBVaWVu+IgCX2v4kyIiBUHKOvu8VFMx9EDa4CfG4oXscVccv4
y1+KRgxSiaV/q363jElOKbyhDP16XSrrGfgCjXCeBoFWfuSgs8WYS6pssc24BcC5P9Wkm60GW4D+
7ZAtVSY8jarcabXgG2iJ0s2Z4chLkLdfHAh5xZzELd8MfUEhL7I6j1Relp92Ykq6WvX5YWpPqdL7
SLR5v7QZPwqyK58ure0WZf3oa2x7St7pzYz2mH8gpzycY/hYIPJfVSmkhCwG3aJL80sshENm6iUp
iHbVluPGL0tFUj3Sp8YE1MziOT/O+xJpwskulzW5lZYOtoudD1rh1O4vPssp4eWoq/XvmMgsfmch
GrfnRy3q6n0ZMCQfSP0qjvZ9EURVCOQS2lzGUdqVR4PyC5sLG7CfpTcfmfAqFLD0ihv7JQwa7H0z
MFmHHM7IuD8XfiihtFOzMY1LOFPGnsy0v12hVOJTWM3TzDVPJtuV8wdyNMqO/sB5kneEZBUAwm2p
nqKc6km8waEYU+R9bEC0ho5OtCiiUW1EYrH98znvaLP8Mi514HCeOGy/uA+wUfGybF2ScbMhuU+o
6j6AOf64B4nyE7madEVuYekzrYw+aiJEB7cw3hwLrFY+ZZLK2e5mq5jElbaYRhY6xL9uayvA2MJ/
ChEDAiFlp6QTK78ADrcQ8dFZGRFU5xKaGZWypEdR/jGgkYLoyer40RWJxVeHPhOxJC7sfCn8p6or
VrhMUeNIS87t46vBLFn7VnJy+MFUDoJRBugMHxgOv2EdZRJPaCk8mg6kPtsDT5nqaGPHqyuOHsxy
Ghz1RgoFr8JeLf1c70f3d6/9VhbbwwImpBoV7pqi2s94zbs7MezxqpyVB868d48VoCV1F2i+Dvta
ESypUB1gpKzsmcPGmbdYECNN8vGNhQIN+xb4qvkjciM/GcRE7BMfpowws0S4ae3nln8LYsQ/TQ5D
R7c2qo7gw44dPHEmjV8mcRJfr3PbXLLqGDnvMcENmih23EjmWuUrEEj+pmPHUVdap/LRZ+6u5dSn
qd8qb6LAz4dGGw/+GmmsVLdE1p8TDpB8hNiy+X3V+Fobd+nwNuqretRM+zhGwyG0vAnE9VUtINNQ
98mtSGf91vXJfzQH00prPHrc7Cjq4kWOMzsil/evbSbGEVOA8cghr1LcbvEV/z4SjhXXtmSXEMNr
EAFnLPVy9L1PEghQmC0t/ArfhZOB7reDFm8P5EU9hr1giuUKb2QzDU8X7nxVEoN/gxUex8l6swI4
/3aGbsG+HU4BvSMhsAyQtAJtPzTYZ3BEqWQWKxvzWeTgDNHYVaVjIZ6PCSgbyEHlnPXvMY5jTaS0
719mBGJodwjWpykg64ClQhGtI8W4wN4eALRrQMXdK9m+SyrXsZVxZvvrw1503oo1n7opZQSaRGxs
kHBN7jB5CG9nZDcByeDg6ZNcX3kwQcG0n67DUX+N7vd+PqOU1L7QDL8OglFAn+bMkqtcNzPkGCIW
ZWBbU3Vb6bjFf1IACuZboqlsW+tkaPKWmr8XTVdjyzO5JAfqWtgAsXo01HWH71RTmsVv3EAEz0BK
zGIe2lWXCe2VkQTntRzk6fgC8EBLFJ0Pvpm1C730Y6sudEMTa0muq14m73yQT0WoxkxZABozTwJk
1ZpRBKhi19hcdq/Bl9z8cvoFNzNyUal+pNeYGmPmZDd4D4OrgA94HPOLKnpjgHwpBbfWIikCOCl9
QnJ5FsEyB5aw9cU0zb5jXqVwWojUNbEMWM53XFSkdzQ0OOhyx6w1pbyLqOfWhyeSX6PgDRWqrvV4
VyhWtOnx8moge9qS0bob0CYt5FogGis+VmzBIqNsjgeqzLo7QRcrpcVQoeeP00pcc7fvLi1SdCeY
eCiHS1rL9MqdefbNfFnPJwcjgFQ0lLj3vVcVKQl9l4dNNyVqi9z/bxyXdmSN/1xYVdBOWS/olCJP
SzXR1UwkqI7/4gGQFyTGTLANFya+FO+5hgVGlokhXcDFquKL/XCpjno1O1mI7XM452zokrIjQynY
w6oFXYhf63jZGY0R69tvryFTK461Fp51sUz0V7OGV6EvP03TjlgA2GnJtW8jrgQCKDvWkZbgXbBF
n3aoZpdb32F+rbAeAQe/Ks2AwdcVdTNBTHSgBwixCP/0SWd13eJifszoSSluhNT8aBEQIWgifpzv
4ypV4re94C65K3tFvIqFAxWnvyaAzbFjuUFfNuWByyG8m1z1Vu5O9eyLDs87qWc8TgrVb+pOVqVe
sAtL8e8aGmCjAslZ1rrKcy4dqBDJU20wEfqD/DiOZskxkSRtxF5goF4QPA/LCnjEjKyduCrD5/s+
skTIpBL012XkN2xNRWQZqCxiOPm3KVgCHLk2GHizSYfschc22s7rljueltGy6y0ovyinA9qJQByZ
SZywLmLEgFS/IEOXtJinunWlOB0KuznIOK2SjmfYfE3KHMg1kYV0HXupcpoAB1wKyNfkSGXsH0pm
9QJrX2ULjWnwF8yQkLGVWR7p8JdlOXtI02MaR/JUOIWBMNjXuTrl1d9qMKA52xBQZ+42bpFu7iq3
mHhpbmYlFZDbY2YMP9lbxNEzNOTz4PEs+jDnwfzrI1GWSrReGQz3sDsHyXdIdqYXV7niWmU2/Np3
W2djuhpWASVRfH4JaJczkwg0bIqF3Xtf/0aq2v9/8bVBbJM21of16/2I8mHowOgGxDTIb8Zl/a6w
I4iK4EcIBRIGY8K8V3b+vrq5sP5J+T1xZ6G9FDhQZJ4kGUrVqoUmGIFh30y4quXFMsePbSY9EwsQ
NQiUDaofLSrrnk2ChFM5S+oq/YTAZnWKAdgELDOAKRDw/5O8MbscP4Z6vgSikrY3x/GBSqG00GRe
y8iMLlb6ofFDd5MzLqAZ/zIX1frhFoYiHnrWKD/1v55DZr7T6Vp27bhFthkDDfwV7qs2ZFPZYUPR
jHG2aieWdOo2UghanefLI87i7jIMnoSwkbyxnJJEyIPRAxJt9/JYrHjOqsvEwIjCIIfOZ2cw5xGD
Zhv0W50xoYaLS8h3zCGvubXgKHs10gEDi7hg6e11Z7c7EiZrTK7PtY1VdzBk56IUonmVy5oBCUOp
NIBQznUYQxgdgOedwOlYM1YFrr0ElIhgWTYPpMXMkBgXi1yc+yW+Jf0GU7PoZE381koeAjmYfZL0
gmWz0UXqsO+NOBtaO2XdjDvKrkoqfIQHKTm6fH76XvCSB3lwK3A+r9l2nA/GLKAzo7blhF94U8SC
fLaut9+tSkZwOGTXuMxWoef6VVoCLUBF8mkVDSczwKdfwjWyyVOKfMqfeewctAJNQSa7tcfrd0sD
0NEwmXSStEpStqCMWdK6Ywg5Sofh5MzKQy9QyIYeQqloxXZGouv/UW4+KYpgwgufhQfVk3jDSeV1
7lJlCS77TRyPYot/PXpffrXrIrXnfmaTUxNGde8dzBwN/QnD97qXzFs3q0aZ4OvQBPDEtvVPT+dw
100RKGO9YV6PpadEyump4AfwuopFU6i/ATqclKGeqKowrI2VAXyeou+M16AwjXvNwD7zDFfs5FXt
/UZvI6AKxXA2geH/myzYnXyET37O9+JzPQgX1+5t63XntTMz6JAIvIyAbKMqN9ulpmCTR7eAJ8bf
c9Sc1jnt7Pvc0c/z/XwxHp8qekWV6kMe1QQ/n3R39bxfg+6a9Y9lk4BckkK7aBIkF+zb/U3NIU/B
TiykYI9/lDvUS2aFbvziqpqwzsANy5eokbTPXGJbJlt3qO9GYj3GOMf0o/NUVhw1UK+G+HAOOFrT
bIUVBB+q37raoAxA8pbCmoMvHnWzXthS8eblOUnlSMg10W2lkd40BQksaxiOWE+yJpEj4SOuQaYd
X0zIVC8f3CpUhwSdEw9Ryyj7TScVzztl42tV177lVW29ni94bXLOyqwEc1DWcCWvqBZ5KOaVZbGX
VYDLY2I+fQYmvEnk7k7M7XWnlqkhsTP1wRiVdlTPdTtS/EK6mAMIUaF3NQTgmgf1HeBMqPBLjezk
aER/fGmaOtjJAj8W5vPqKxRY3PpW48zOUkoDB7E3nspba1REBqK9Qqg3GT64qAIkI5PovzMs1c8x
72JMbs0DUCrLsgpL5p6d4QktMwc6/FHempK5XJJVdWez3RhBaaMmDibR6yqR4l1n2Ol4GaLn2WsM
iLXb2RnDf4T3s6RRpLk1ZEcmYEk9VmsE4YMBy8quxDSHsBXlIf4lypJm3i0jfr2PYcGgcif6eKCq
XJVrUjEQ4vJF2LZr404LD0InoIINfC03mHiPkGHnw8WjbBxt3HmZiNRBn52r/8q8YYvhT0hpF+zV
JwszQhB6BQrb3J5Yv6OxTrabNVBPpbm0VqnNcdqMb6tmEMMGqxUv6Acjf73I9b+dOYvUrxm45dqX
2/TyhQNN3gT/djIU62/9hSgWoxyj9RIXPD8NZux7c4yncXFiBBxy33CP1hiyxv/d3TJ4IOiBcZrh
tvA/7FxJg1k0HW20l9Qv0r2sfAcPd0Pb4HptvnRPvRsDIlGldjXkkSVheaF+ZtPMgTp5aOB8dxoy
TeiENXAxt5Ab854528qFF9rFJXOKI/wStEdsKLzHM/WUenXhqmLSVgEjKYxHuvo1aw5jlXVbdajZ
xmTyYLfsve2dkyq5pOTaNJcE8Bgb4Bm2yfsnPXOOEZlh89gXR659k5D73YBCc2iFsYQfBljcKXfu
b3a3e6Wr/AkKWQ6GzQ2Wv8aud3YcYq/ndew/X40ARnHv1b8JdaQAMf4WmJ3Y57XDi303jeaHWn5w
Q07pNXQx1NnsbyYz/UeS6hf5BKNWwzKPr3b1JtlDxUfg6cE0KahbE8BUmxD853kAje4wQSya8bRS
3eNgCvC8MyXViPxNvQNI6oJJ6SB4sg3+gBfC7I3ZOnjgMinEZZQBE61B4uLYA95lEISg9+e+za95
eipFzYyyKZOx5acTPkak0o/c4SawyfO5nv7bGSJVpTtrIlDkMXw1mOlPvehaw7nFIrwhG+wJi4sb
0+ral0xEy9mfW467jDEGhwfC9IXVnb+4H1+IiWHn8TOnIlUJ0uo5ofLB/Kdd+aKruU9VuoolS/LO
HYIe0Zb+0Wx1htddF1A+zKLc9Luq/SH3G1MArB78spjsCA2glln09No2i4kwjhFL0ol5g/X82lUl
aqgyyXJdPvMK61SzDI+LeQR+99rsgZENUWPQClxWwJVa3mjZ3NHSmHGgpZ0+/uRK2r3SIcbZNes/
AXd3FkhPruIJS+xt3DTmnMu8s1msLPMRJHuubIsLjO9APdHBiDGNkTybcnQDEMmvtX1w2ntJKMZY
wSG6gps/bWWGRE/KGJw5ryMF5WRKkolVr1dptyD/6fusXgsoifNpc7rniC0AFZqQ3QNh9blXWKLE
bx6xcnf69VzxYn0dJqZhhYCA/M/ddtNCPxOFQ8UREQSKlwnXxrmkRSEZaa/C0IxBfjp1xHIJVXOv
5zaKu85hLjFdcB5p6Csij9gRkAStqYHHi6RGrP2uspvX/EpM0hCkLXu1b8ucVpPUFe8DQx0OyEJu
OvW+VC0Oi5GeI9J5GHKyOAmGFe1bF51t1Z/jrV6BNQrSnnVC0WUncdc1cLcXmIXsh7S8DmrW/UnF
fHL8e/TQL3qYglNohYJ/Jcl2ioxXRB1PQAg9Sns0N6GjDEdPGCEJnNgh1Wh+gAcyEczzhhWIoNnm
r9khoSSwqkTOhxmWPbyiskIsaqwbJeQEZ6/fnx9yYSNsv56olkkI+YryIFPgLNTbWxJo0WQYq7jo
sMF1Su/UCaf+ihOWB6z1dLVtXY2joh4ZSYmbLt4l6Plx9m0jl5Vx90EiKF3k+8Jcx2AoiZYWT0Dd
rFa5trrDdjaEQ2z1VryrIRA6cZynYK5N4zwQMetorXsykKzElkNpjAXs1sPuwCzbFew8X5oWVnmO
n240Cy3KMB0Hp41qKUOIaeYL4lutsDCPZNGiCm0UHslMju9JMLa5/KaGfb+XYdnbGImINIgVLW72
xI16RJcdHdaRPdGIVvuLIsZJMq28mtggLy2n8kNu4UdL9A9pwIXviZx4YZRqFYzZm/ih/SThl7I7
OCXBQ21uJUdRDbhFBqhYtR5IBHc3JXUSE4UX8/0B+dIgWPuTmuoU5XvBd1sXJZaFDVqM1qDwQGSW
homfyMUcZHF/dMqCIsq5MQVDi7MHrI/j4lYkka6p44UubBt2WBwb9xzDh6H3u4LiOBFIym+R56pt
0v/1x4v3BsxN+RqXFTgjiJ1QZYVW1z7AKLs/zHWb2cSCT9mU0v79ptX/8pYc3wdaqqHL0QHdvzc8
NyrPNQFTz5APzOOi+FlrFJmrnSoIrvlGCIGyQpP9L0+btD+X0UfuD9I8Rxf7y28uqKsWSl8eftPa
fYjCSBAdj8ADmBW8tql6ewXHzLMKAmQOOPWZCU6gkHcoqiwghWtHRMNufO6oo9gk/2soMGSib/Cz
kHGYRwbq8Rk5VvB0zLBT+s8Xb3ko+hunvJUT8RlFJmhiSbn43WSiNUglPtW4lSTeJkHAhketa2HY
U9COdrbcYX7SWvD7+gdgTJAYYgvBtf3eE6Qstc6vo952gWu9uOGOB1M1X6YLoqNb0gG9/1SwUTQT
FYqNhkOTpi9OvKqQlyh+ReI168vPnnkhV4nBiqmHgUpXT2lIf0mKgieTET7SoKwx8UL5S8u+Kb2q
JXXwwEWvdetizeD8HLvepVo71UWA/H1WdLkBbOyY92l++g985absW+Z0vHx2G7yRqgUXy2B2O/Di
6qm3iflZTJxXawOYcL3o/CxZb3orryB6WQu7JyPX4nkocX9CEAuyDHWlBZRlJqd03mbERKVCipEk
CfT40Xej1y4wN4RUqzxQN/v1/xS4w1pDDK00fU3s0GyK5nLLZgYRwD12eUlpbaDzYFrgi4kNyNOE
c3W4IS0bm+i3yyOdcBFNTCRANKqcW+xm5gWRdcr9/SXE4VAXWhfETveGvGU8C3DgZ3z2L+opLDb9
6YihA7LSUav2f7BtD5V8W5GbxBdvxvSY+6kfKqoCndAAFig7dMq2dR6pFJJIVMwHTmFDQrKhjWVE
QYYHyO3kW8zbQ6ToEBPMrojWhkN1WAc4FtqjTeRmrwRIVH6hfxpC06Im7imgCkvNRMieW/Ny1Jeo
QWGOVsfIY3RMWDS4TcAXHFXAJzpWQmMxSafhCpANG8R9SuAOv8rUTNivPLVNVdTt/lnqtSVyr9lO
/59RpyU7JkikthGdK7KT68gT4vo4E5nM2BUyBALWisXvhUZXLjG/v1RbtZk9/VyItJiSu/X77vzP
7sMBdfm5bJixhtHE9g0r2kzZKUgW5GRRWmnPG6lLTN20t0eTHGmslijVnjl+EZ8cRvDOTviElnOY
gE0CMyXMDlZrC0j53l5vqfSxB3ZRZHVdjITYmN16nC6tS0k/v9IdDHjTM6U5eFpuktNQMvNAf9hj
g+zpA4w4G1FrrObkPKPPvNDf6nAZ9lAKGr1DkSYfNaxf61TpDgvrUuD1XebbiCs2ADeBMp7k/2SG
sReXgufnXhEcu7DPbwolbWesciNlsZepHZI6EogsE/6Q72xnxw0/ql8V6YOUpU/Ykbl9wqphtHK2
csOwvpg+joLbbI9y3kPqHpZ9YTvGSFgc1ASJRgEGGjhvT6oMDg+1r9FpBj0E1xdOKqHo2p11wcin
7xad7zE7l/ms8uGOojQR+CWBF5QXbzZqaLALBo3bWLWvCvwsL/CWhnBvV42wehLWnkfNx7VqHWsT
2ZHVpiPivyVt70KQ7AMYZaJjAfNQoA/+K5pb/0yjdrzrsU9O98d4nWxpkIQDI79JesA0OftM5Qxx
f6EVgcmPnpWrEpOjPeOQ0ZHUJea7c0kd/JGyTajs8pq+TfjsVDa5pTT1bwsijCX+ml5b1tGynrIl
6xeSIe5YTSYPvhcyU+JMMawoj+mxTOUXNLS78nS2uh0omBWpBQvbS4zrY6ciXI8HWayzP9fMlJcm
Q7uyr3Zd2/uUXQp+CWdM9ks63mLOTVUptaIYoxVL/vGuqJ1DjWImvm+g97hQDf9J6ko5B2fDWllI
8IBv4sSh7YLVbZ0zina2cJXyB885nu7BZkNsyQvCl9xyo3QUac+sMDj4W8L1W9cMJTbtWGwfFdav
PHTlWzCwMMgSeiM+d1D430ik0bUkEb2m+RZoHselQMmKdMGKgQ2XZEdUXHdQFxZw6TsRM8iFi1ty
2+0Vr5RmgADgUlQOpDt8qTyY4BswAch8k4nsaaI1a44fsiokGDIgtAp5lT2T3OczWFe8IJbHRjv8
os2Qo0G+2SLPN6PsfEt07gp9Jx5oEaDCZgbzFV5+EG0A/AP7SScFBLfGZGQbaSMC+dHHGnV11j/X
g9s7ZIW3s1Wrl2PTk4q5wKnYUz0ZA4NaDQMYF4U92N7dzcqRSnfo1p8TTF8wjeRpsDGkXcD7dthG
JaxYIozfGrE67i7Nydbc0dshfOOYgsq0hcpiR/DZ5GWINNXdYozSEUpoxDXtB9GP/rYgqc8lFw2+
DkBVfc/t9nxvgIIGk1L/7jNCVxeXvrHKOiYMPcyGrN+v8BJFdQCo+cYidTJzUHF/o/UaHaLrgHLn
TwUDXVR+Wu6tfKJpipvFdT0wstea13jZoNIu7/JULnTFyqc3crnUuJYw7vVsun4a6f/yHyxdDBi2
145jV0BxZhuDBzyGbllBatFDas5m+D2MSDxLhhlLxJu3gSj3HMQt587jnCtqhdz5MwjcRHS7eReR
o+qEnUEPP0spCnGT6EJ8+S35xwHa++vpFV/11rxqCH9qEiVkhSvBHEv5odwg5UXfH9uI67ruYfGk
OCQL9RRbpzCzEqlSFWXSKICmZsbhgjkLDDPfKojzzexIwunlQie6lBfslrq9ccqi1vF9nBBS4uIA
A5drrhDYEvvSzGk+gtjnxqjhrQcjXt6Gul1TA/ySL0Bv7bjL6OlDnFZzgB49g/5CwLZ4GtVrHFgO
Q7A+40JzrxhUaMU12hr5MjzYOx/XHwA9kv28Ja5lZMvwBuJHr2C8Ir0bSVO7vbS+HLC9OfQUjqAL
560sfDGPp++fAmG/LD/fQyOV1TSL8xZ1u/X/6iTIOZKagmemZoSXo32b9ZkAQ98E3GR+GoQNYlzp
1C8DV3F4yxnoRbMucUBikytoA1NrZZQcv0CqH3v2ZrkU8jTc2nr/Iz8hCwqXHquXB/HKA/YnTgqL
nh4cf5FQIBtV3YgFOZbLBphmyAZN2erUCz1VJ1CXsgLmkwSK7tH7IMvFUqmse83fg0hsssdm8VZB
MJk+fGhZbM5M1yh16SGYd9UePPDkD3Hs3dkXzQB1X0WxeGwSxu1ELLe5nIjyqNOZKQjxLXXnXm0h
SGDlezjsEvug/jNdyp/QX79apoGXdljkTaG95loTTUzxBd7Ceb9LbhanrwCwnGEJDgiR9TIK1RYL
Qr79p79s7rSTXXQjPBM81kyR/MeCLhFCVHnTr3tVzCsMJSLs/7ufSAr8oaRVi//IrBBp7jiisaGU
2K5zO+Ttygi58PuATff5+hRENHQObnSADHVZ4Dvqq4DC1A+jgjY4uwFuHNGGkxymZDCg9gxBXDB9
T4aJrQ9l10xhMBw4GYqj2UWL9Knmq+HLydRmNivlxmu4cAYDVSldu/BDt376qVxS64eXy3XTK0h7
eQlY5pLKuhAY0MptT/l/k7zCjpyji2zzytgBTsBGhi96Y76vgAYJHefZhDa5lc55XsP1KpQJHZbv
zOciLcgockmCLyjgQm3vWDy1n8KkrVtI4fjXV2zgNwSkUcdmsUM0gbP0KwG+uqUsQKNlNLacHJLd
NAB9XdkFBTNQ9PSMFTcMpyWr1z7lbaLyPWQHefL5otlxpB2pN40VLjQ7igu8Z7vApWlSWvr5pdcw
+Q641z9mU+TQOeW054leVYsNo31LopjM88p9jIVJu6XH5oC3iitqeil4jPewIcGuOaTGhKFANwBs
K7XKXxaBKVAnIDRtTQ0UUOV3v3T7ObiY6htHBlitEsiBuAzmCcYu0XZ+mDHFVNeGvFqEwAF9qYCP
y2htdVbyCEg7pTTn4FjaG97c6mjXvFYASFyH4Q1t6p9BwK0MP9ftTS0NSmtCu1ljXTbQTTruRzXb
9qXuAQKhGoGmzxzXFKPG/hUiJ9wjs3cxSn4IkWVwDee2UM0a3v1mo6mIxax9oy2nTl1Ca5chfGEq
Kh6GlWqBXR67XhiRsUUc8Q9raOGT40P1mlsh5jk4G50g9/v8bBvGJvDMJNIDErWK8GbR3wZNNYDb
BKxi6g59RmUPDX++DeiY9D4YNYf4RjFNvgxYFNeyuO0y2s+BjGq2Ju+VnacoZcOD585l/YEX4U80
DKyDimSYgS4ptofp6RcESRDiKJeCMZWqYs3moKi79W+QRDXKLpvkgZIaylLOgQEwVcvzXIYNXOGK
f03MMUEEt9o4TPVOjXUbmeSdr74HIFdITi3ToQH1IX3bp8gRPsvZdxGOGncBsujDsTPTGsuX2yNQ
3R7z3gOYQjsBSmW07Hzwx7U8zPTDVUrWBAPmoSuXEX8R0u3fuURSPL1oJfAK3/GbJWRKAhjWvVEd
uzhtWaOxI+EnfZGfCuVX05lsjJ9lLCG4AvX+7THYRJwK0p2jmzylm6A0J/hyo+U/bPmXqAkrsTIF
T+nrykksmlm8JGobn3XjrjNXDDxIRSqBbr4YKxSArWjHv54AR+Dyb8+3S43e3xEILuGvJHnN4Z25
9gNyaLuJJybu7ZZfqeXeCQIT0UjW53eIA+eqRqosmVDfEWiqD6EOCtDLTAsmc94Gl82AiIVHrIpw
ELvE1NuP/Tl/RyIbhyus8r4YWJRWUIFkojRLRcgGaCVnMxo9BOyBPwZVdCdkPZkwWSFXZMbqDQEg
0gl3ZYtI5+9ZUi60ps7+EGAVfkdjziB0oevl7RhITdX9CHo/S8mpkGpBsO9jMI7KepuzIfUNxu4A
+yEvDLGdmREDIqC6vTHFlPClJ+ciM4FCDYbYpN8m+QVk09fFiPOFUTfVEZKrnKSU0FymCHCw/8qr
InA8U56qMWh5lbz5FGOI7CQnJtFXxssLYZ2N+ZRZglV9uojonsu6i8ty3Wh3UhWOv2Y4Ju8QuAGG
oTph8jA6mxREHq6c2UugCCvhj7l54vtQTifLi1L8B67snNHyMWvTSl8yzYrubACQ4lB7V2lcZnGa
kreRzk1OS/AQWdn8EzoZdnrjzyNWrZVUv8bIz8+lMr1ZcnkfGIt4GCwxZRzXJ6hgCywXJOFkYS1H
53BF88HT8iHSG6ltSAORHLLCZmni3Sm4iucDXsXoDTDAZB8Kbz8g60zZ2wAtZL1/m2MuPmlCdnWE
urLZhZJN3gFblWUbOye683Wo8qMWDkHwUqqIdLKnsU6XwlmhgWpCAzJxdT5U9H9bmv+qxqynkka8
/N159YYVZqrrdKBcalAwkpFCxCz9RwUIfKe4CfdJ4yz/jNrNGdyeY0o+33P7hHKibmW/xMHPTPrz
2mBSIzalZ+FAvpdp9qGBhq+LPG8DKwTPa+2ZhtS8PXAVUZg08uy6xQ9XqjxBh0Jnp5X8NvIUCUWO
nl+zGUTZFwp3hhgnYMNtukx+W3enhCsGBlOofjOz9MaUwuC8Q6006hl4zf5H5HNOCtMRyuJ6f63K
vOIwcXAJ+ciVetkUD8RIdvVHIOMp0hKfsONM7q398fHq7rdpCx06LoJui7e+FOTPgS/xdxHiV66C
ZtxLhi1fX9SVfv55Qn3W38mdVbzdIlt+IKQv0F+ktU5EZzDuF97Ci1OYEYVKgGGOE2fOkqDNfoeR
/AWKlQf24A7BHbCGz1qORvP0wIUpoFmnCckSL9WpFUQ2Tu5wqxYBf2B/o+bJjZO36yiealJwKfn7
H2lHq/onpvEPba1x2JjjGb0JznaD3j1254CkwGz7w/hAMevOIVZBQ6kLrwXPoOCcn8pO8xIIXtsr
qaZu3/hnZ76iVe49cMpMF4GIT7etXHj1FYPzjDkiUaK6YWmYW3onP+I5lg2N/gxQcJcKK3G+kAVm
JfbooVGKPZX80OZTEsZX/rDyv/ip9OvmmEisqJL8C6tPcJMVKW8Nl09JyP+CpCpJh+Lvz8gWyakW
dIzTr0ONavVth2wTcO6NIlAuy3GqhpDEc1O8wxv3TErusFkugbKux0kEm54EW/rwICvW4djnRJhq
cskhQha4bARx0c1/f84BnbjJ3N4U57DHhqfH1IfMTb8DW/BpsHSIGRl/xDgxmbTNw2Xu0EUXoKac
bYewpYYRKis2JAhq8qToTnNWywtFR2wU46S5An/tt05P3FQM9SKOhN7vHO1rzS4cE5VLDNiP1JaB
mPYTOTsI5SnxqRebJpi49xO+He6rBgeucgaMqlmKmS963EjTifKiuFOBUBkbXmfn5Q0cn+RM3njH
wLt/vhkQ43KL9DlJ09zyNDlZ6PE79f4VdeTpW2XYIa2H3h30Q0mCZ8E32vU0KPpF+v57W8aTuy2B
xlhosErVxScZVaYeN1XP1fykmDNT4Z5sONaqFTXYjxm891dn9BEowzCrxmACF3o3bUW2mG+xPdfo
huR/EJtDHVH8b/wb5TxR4Qad6qWTptKF/oQpzAGf6yLPbfH2L2fHoE1rd1lC0myARoWl4F7IyIj8
Jz8CTXfWcvuh+YyqlF6ep1eW/tSIBkSCsQy03WQvcGv5yVPzpiv9E3B9VrRw3Cir9aj18Ibn/t/d
fpXq4VahmqupTSGAYxARFDx2QO7tUlYlGen3zxvRcG5eJUd+fDplJ1oF10oNB8Zm6sadjD4CMpQ6
aGMRVxV41cQf0CbxnNTNFVm80Wx7gpkRDWXSkkbCa1zzxji1dYaQvm4/pa3xQ/8dgGN+18Y13waP
13T2SCj+Oq93YLjKuQ7Ijz7X0vyiSIKogPP5IHPmd69zETP4BVNX/oddwq5G6BYLQzFTA0L2boOA
APocWP9c+JLdiJ7a67KqdSDDqq4GjRjYzBtS035ErIdLJbF4RPZ54p5ugkbtEU9tpDNdDJowgC3b
79ACi+e1uQzPnZHLoQmTk1YM6JvG7pdGU7JGvKOURud/rGqsY3P+K9z8Grb7Aq3+Lx4lvc3QW1yA
D6CgBr+Vq8dJGSB+N5qF8Fu4n+AYihSmYvfoYheWyheyJSYb7mMxiFOg4iWK3VB8SyJj92rKMGUj
ykvcSYKCQyMwkTPUo7yja4RUNkA4SFk2Ny0uFpefMUQRLFY0OlIuUpxmrfedFa9PBXg9Qpkwcx4w
ZTzne8GVBJ4SCfbPpzaCrpasx0PCg7ovOF40jus6+PzjPGMA+esCnZFIIAMI3CwiebQM2huD+x7e
RwgI5mNKg7KuXdzQHGgMWs0r2T9JRZiZRfwK+sCW6nk1GTNZ+IIk9dG5Wv02M9/cpGDpKe81Msdg
iEmogK8nIEMh+GjvuvD/FfzOUVvgiQvCgNl5rJNrSmfCRxuyMF8aEZO0rczLGDB98SwzKj9Iua68
wr17nwljX+8H4MG9h8qcFHKquJvnP3vN64ZhSIsQy8rONk1+yu8B86SYj/PdMXxCOq/YcBVYan3u
0due1MTdzJSAFxP1+miONNfuGR0QlFCgtQA1OLHL3HSGqSWzEuOivXzdYrfnKTZCmtE+40QhfiCl
YkRcOtJzSc+q0RfMl64+esNYl8QQmV9+ElUL7PoxHR7jsLGMVQVb4m1QKhvg7h/ULb862MgY6iic
FEQfNowa1MppRgAC91G4fM4jIUC8cdLuvzmDiT4q+ug3m1etU5t/v4CqnPcVBg9jtCYtlrqFCFug
SAfqwtWGVESHoAh0ab75NGOU1w7rtKcfgs3qjdKJodNXq9SdvmrPU1juAYJPPO9ws+CN8yiHF/ZB
ycQMuCBWJyHfu/siybqITCjn4akwZhsmOHHfB2SHyn57TX7ikXkaEltdyARygBDDjPyVS0srsIVM
PLvUJa9fnv2ar42hacUERy8gF0Pc773hRP+SpLYq0AhpVqDK3grxGXsMoO84+D+QpUv8yQmHT+pB
TJdzbreki58NHu9DKP///yl3bQQao4Y7ASMV2Szc+VsFopR1eXUfD6w32+rNZnmiu+h675VB4m5f
3I5XMLpcCOAJN7QOAg8x1wXO6Rr3Snw0UzdvR0rZeiMs5AOp7bLtXOWdwT3vtSjTyVUqA84L5T7P
L7dxMYbMd8NSDjEXvs86UAa1oju2Um+b5O5fzDXY4388y+fhj9U3PLvWKRTfUWlgHsR53QxYYCPo
mEzjU5WuMnBGKJzO+5nQRQX2KREM3M2QxZFHIScp9WMP0awcRMjG9Wd0Y84pps0AIbRP5CisGtSb
RDIUaQ7BHI5zFYJ/Rc/QzixX9vc/nAqhGJdyaDbhgJ+q+bmZZSDWhx8J4Qx6NYITVkxDB/U9AlBJ
KsFPghD35tsx2hCEOuV32stnASLS0SvpVH7orFHa40alo2/h3h5hqixO9vk9OcBad9Z5rB6mM9gK
0AgOcNZlqgdA4Bf67f7YGAGG+DvUF2th+9Qb+i+1+1apS6kiJ6AGLk9oEBSd24WTQWgXk5/78I3I
i811bX6akKrOk73TiRvGGmMST8WqF09CntCev1aIAQtJTuxfc0E/0whBGXTTHvKJJOTf62VfYgpa
V1wmAW5i+Gf694drIU0h1NJwELl1UU+OVheNdSGcWhi7V/BCc/vvX0DFlxNe3wPmi+msKQH46/5V
Df9UMOBBtLZKx5+vPch3qm9i/8HnetVSmTDKkMFFEj7E0XG472ctQt8LR3IT2n5QkT/CPhdJmYZT
VptiLXkOUYh/OkOtrwd77nMKFAx75gYa2LLy8DUKaCNzW0P+zIxm3F4wMsbdeQ4IhVd5DbT4+Xxc
4IzDk6XjStC6WySeEHmjRlooN+bzsM37g5BzBLTPXWcEH4daXGcZTyPtq6cLyWYeiKBfXVyVES0e
SWWlxkZ8J8ZUx1mHpDeYImcRqzRTDUQxCPrUSkkSqUJ1V84wo/I8N2tT3dEV5mFcKJKcW1nPCDOW
SCxPWJGYSFYbJAHQOD1hneXhBKNZSa626UJSfNPh4nUs7h42MjfVu8DWqx8VuwgN8NjKr0oh1WCj
iGsOG6eHEx74gn1oRJy9TyHwmdPZ0roAOEUKZQKKb27/N/9wL/mzGfgEB6W8FtT6IZn/Tuc8ZMXh
mLEQnhd+bIe1Rt4tVMubPlFDL9B9A4ypnVZSd0VvuqJq2AnEJznlPTt6fJdJnMt/ofhO4PBEOyAb
nLxZslBef8teKtywHErjQtPysmswt91mrXepwcJeghU8TlLYfQz4sc+WRAk16fWjf4aDIys5mwZd
Mhrj09TLP6jbB1JXCXQVCZFZiJ2LQl5IGhfRp08gkrohJFjEwe/6VNnM/p42zaIn+xyxVLrbtd1Z
rwjdScv3kW53dn8nuyCvTCttv/i6WLWZDO8p6bfeT666j0xNIKtG2x3BByUQBRYQWFb0/H79fuPK
nsI6DICyuf6LK6gJ+TLcNqw7dHpfPwwmiHChNvXX3KFeVrdsVNJT3+eS1vEmX241N76XskJ+HxXe
mvOMt0DmexD4Q3IyCqfG9lAScMeRuNgwUucS0wx3DO9X9naMNNHK52sLKlHEyhj6XSlstZ2riC4r
gAXTVRQF9ZqsxoS3ZzEtWRS32vc4nIRJ7Df4quNlRCcU1/AxCh3tF18zgTyAhIYuK3ZNKPJ/bU17
UHCTkbPMrOdjJAw76Kceb7CcS0ba161SfESCD62kDm1ujatk5R885jNiaHpCnNYi5TCrbyTJsvMn
VAtRFhSuxBdv+ji3JwbHNxqb55yKi9X+4txL5tooc6ZhTz8Z1kzeYRGwWWVlO33Zz7im+90thEwk
Iyuazwo+EdnsR2yi/Bj7r86I9BFuMhjnbd2UuUy/t4AMPmh9KWqcRt2Q+9881fhPfic21P9mw4pl
WxEnR0Nqgy52Xd/f1uUk2di6UDjs0ZSQsJLhze9SFlx8kovmcgVstrlN80Y9TdfObDclt48OOSQe
ejE/jCdak+FiW5znE2Eo7T0T/BmCS3vw+DrzNLItOF4VeSW4pp5kOvOCKcMzZqq4i0ISYS8FDom9
dWaMvsj7A+gPNZERAncXfcpqHG8sQBUuQBz8mKD6cpfDkP2MyXqxNq77UyWOMGI0bjDEqXpIjmIw
oin/hXH8RtGhYFC500a+8EQtx6S+1lT66m/1A3mJsQEp6+vfoCvmv5XTBFkUnAmT4BdddcliJECD
wbHcor2y/hBtZRXVq3zkOext0Xr9DwB5EcWne7b87djZO53uE4wxgytLXze8lmv6iuNLLsGxwyxd
OJuSa82VOmss69sddpAwVjMAWmyjqex9Abi8l8079H27MFCjTt7qzRQCEaNX3N3lPgKmgkBoQSe9
cH8WUhWTtRLRlCiVcrSPp4A6cTrK52QidSGk6U2sV5guCesd2ETykt4DIXhlscDiXo8rLn7ZC7g0
h1OGDTEinOC/EZ2aDrC1n//cHG2NLxVAmr561hIKfKghLvXMGocSaZoZTfHTAjL6iW8NEnLzAmv7
xs0V+Rmk+DWaIE+xs0LHB8shnqVIm6iamttwOHxb0203xNJzWwodE/AR0iEgiH9Kp/fKtkMJd+Y/
V0sTtrprAUQhLvZus101zMHFfQ11T9tz49dAG8oPXoiBRZAxSq5sQ7TpuQ+HFQ/86Tuc3j6dRmOi
snWLJ3ZJU4Di1zA7ZXoWkhayRVCiRV//JIMsyDX4O1PNzpMt15iqWVM5WCHYyI2qQoCwqogmKVnO
dQkO9LyRuyMJmxuR7PDHl8QY9IqU4a+hyFbbCxU5uuFSRVfYoUbNz51oIFnB8RG4uOtXdoPfEWBZ
5HRzSZ7SmIlQJbggGwl/qZW/K87wkAbWIoE5bf75C7dOdLDAnZX8wVz9p+tU4kTxaZfpiNHBy8zn
5sU3fXecjywbIyNUsqptuWIo1/OlnuinNSUq4qctQqdCoXGYmkDTWoY88GI3oGABP/ygOu7RMN/n
1crXIbURD/1RGTr2hDGzyQSbnzLG5d3BOSDHtmRSs/ydiMvpGklUmw5g3P8wctOze1yXqQIc5PiF
Ou96g+2XWEm+UAGhPOlC97avi3X7K4cZHYAe2T6IuCohtn4UFicDCjxE6u7q2pGYOqSKxhYxKkU8
BITKvjJEksnyH2B1WU3Xdpx2/ePbA2tJTHLHuaHj6tkFppTS7qm15KEx2iYeH9+LBBrRPmu9x1Fg
nmSzyChZ/fX0jEWGZbX+jKipdHB+BhL0Gr5GYQvlZdBe0t2+mT3UloGwPe2ifAL3asLlUGJltTct
qE07duawAMFq9LQz1OAQi9MNfOgzP0Z97iJOqLYmuE4jHhZUTURk87iwux3pghTY1voB4mayc4Uj
5jxmpANCFk1QbEiTiTI+jR+BI43OYk/TBypwMPEzCJzZTcK7MIQ4FzjtnJp/N2Y7ipKfRxFQBguJ
VliJIXP7JXO/FDszs1cQ3TiyvyJXRolPXOK02B1Tw1xuJEAM8TDdxhsdxbTCLZ0reF5Kfb5DBelj
n6D/Nt/nkRALKIhReSl0gGhj+jQv4uXqBK5vtea1YOxJWTc3Zo2Oc3ejUc1lzak6sEamI6mPDpyU
YJA+UvJME/1mB22JEdlfEJMjdBXhfoM/V7KOweEo0X0z7SRU0NmFKJOeJ2csZ2AAo56Q3APPu4fD
kWIzHgrKr3yaQoHjQg+ByXvZvu4zlK8PK9Zw8p5Yz8MUL6FsxkltltEJ8ZFZAOaiYZQDHEfXOfAK
799ZV4QE9mM1K0GIfAPl0NRaP9T2YnSrKbKPo8S0g71peE8yKoX3pq5fhlqiKtb/EDtaKrCkeiJy
hV1A4IROYh8TlJic3ITbwPJRxD2kVTUwuowYErBTUa4y6cMRUGhD63IRsFVsTRO7C4K6+8pKugIp
3t7Qg5kJXd/nGK1o6aEEcGhgDUKvQcXwgm7BN/eNEFXmWUh0g0EH5VtQCM7L1LsrXPf5VM1qvD6e
RCXwh2pdux7WKZvapHNIEq9l+EDurp+1XD+gUYt6ea7PQVyN/jQ6rMjXuxPuhc6msOzC8bhVlOMP
tmmY7mV5HFhluAVsQvq8pt/pQBeqhfmWN7N3Ipofc4VAyw1dPvpYG8A3vdCTY8X8dlFfOdgqiIqW
XGdBppz1ZXqvPX7Uds75TBhJMTCfskfi9op0ysEpL27rZxZ53Bp9KbGKcp9SZZxhSSw1rsvyezNE
h24xb9WMz5ifyP7DFIWZnPcEhVu9NotAM07jYjAd/kHsXxAO9XqrHDjmVSfhA2plGna4Ubt+trHl
kkZnwt+Ohf/dSG71chACWP6w9CYWWy2526BZmB+V12NEEyJuki7JYmtlbCuUSyYCEEDyJZXEIrox
rLNaicRjs1/+HZYS+rFtRtn3UODd70csozhyhwdeQu/QZ8705ky/aoebfvWWyIloIRt+2vjW8rWO
RscqDE6ZvYiGiX2OBhxJ/OsoAJEZXZfD1kYZs2IdIONVnuxMibBoeTMQHPfwUbFDR90BiqrbN+mt
x/arKr8zMXmhUVXdySeVRVMhywZ8L+G2qjdk7sJ1R7OCQK6ClIs72i/JtLy0su9gr4dkCk9Zjk/3
AstcLzrQ/y7PzO1eEuwEvskkV//At1qssNYF8/743lcSpXBnUEBLrcNepaWS7O2DboipbeD1KMaH
OsPLXISZXwnstWZ/8TOjX6ci8gl00qsUlAp9ugKcrAECijrRKlugyEJUzrspHdMR4HF1sC8rAgEe
WIvwgQENQ8sUT7HAT/ZN+1IwMpFgp2cfcFssffIIf9bzzG3BALyXSyVNUNB8FrUvcgpSkpKqxaHK
ElssRmrQu1qVUKs30GaNpSxmHTkkLJLvfvKgOgX6/aLJGNAgkQchYR61Lvt+5t8FqK73YgCuN5Xx
LsFkc7dtnJN4htjN4wTS1x29yULZuh2oUKlp4oaXAUDw3D1w8ga/VR0X7cEJiEydEvnV0CYDK0jP
e/rA2827JztmhazoIaabw/q2vMXiVS8AXO5IXpupX3JwR5FEJv8MweZ8P37UgcEcaJH48/d071/9
k1ImAttCNs3edUQTGbP9lxO1xPk4g15Uli/6Sug1csxz/Jjd/b/6hDivtzV4+uLq70hFGAtk8uR5
vcK/p+PKePyX1qhTp37t7VcySXmOVXBD9Kki3L7i4P+1znnKrIMC4gySAeh1kpmBh0VgRGshTyVV
FBMXG4RiSo5Yt0dvWkNva+GHghmVyykcQMonBjv17pEXufGdpdpCwCnAPbGddAfOmIw+JIwBgTpS
PuMTGtZ5rbDUeT27lMGXkGmchFsgO0aoXEvAZJdVD6Vn6+DvEJgfMGUDlQcP2cgZjuFIBa3XCkpT
Y666Nxa010G1lLyICC8Qohx504TVYoA94IbrUA4kLv4G0UUkEIfE8oJ6m4obl+cJKksbds6q8QFJ
dNjG4mU4i6sm5bdEPv7nCrptHr0UBu007EXVblvnI6k0NByc8lthCfEZtsFucwNNJzXCNAkIoo+z
p/Ty4kHzEPsU63CNyA8xjlie05kj5mIiiVa+sc7L47W18uIzK5E1OeO2l/0xM2cegtR9X9K/UdNb
89YY6DwLMVHD5z4ZD+mo8VQ+cZg7lOvlZiEIVKJ4WJbxoDEGTVfWm6GP2giulUqTV2EpAEPl22Db
axxJ77oJ9cGKx5XNO6M9AM+jBBI3m+JO74VANmqBMZFuiEhDiJBydqemruqe4T87oR5E4sPNGsAW
TjOPw8Fq9oiMcD9G2tZ4AkkFRwma5oGf5EP/Li4NRcg8zy2mI6jdORo0O0WDPDHSwy9kKNaysYlt
AUvhbwG4HvarKOhmKlnAjTSehxJNxyexviFpMWsOrjSLQK2ky7OtGFEvaoDUKM6m2tbJxaFptE6K
R4RWv+jPsk3utBonszSTieE7u0VuJ3u3rWSOl4rpiE23cSBS2cnKi+Gp83AVoAK6UNf+woZt0rC+
VJsR4F8vDSFBnX64kHRH9Swwxp6gaeONEz8sCKDPcXElAaSGCylGvjNxlgrOX/9v+HOx1RH6foXN
/DPw3acNoBBLxOQzR3qTRUtNgl6DSJgiqq3zWv87opdxpX13JXmgsaM69yqzg5Qx0/Srvfb3qvwY
0PqNfj0sm2LecevHEyi8gABeJ5zcH1ARq5jl+tWsSIM9zXe2VGc0RisUrR5qU6qzUPDt6nN5gNdt
3tdyLnPkzbb2aZ0dEWFp2A0TW/0QKslFNOnFsOMr+8dHvk3PwbS+aOCfWxXbuyFezHb+z046902o
P1KPUDg1x63gJDGaDznM3vFRV5d8eF00MxZVJMC4gKODClFY+oovCTDjnUnaxqZuTExhdoQUronL
JivcPXAJpHDTo55a3r/A6P14x1/2RCLjTbpsQ9nGebD+9a1l5qG6K+U86SNQnhQcJA1o7Xzy3yWb
/AkonjjSqhwplv1xXPXdVUPoEVAemSUGkyD37wiap/vXhE+HTiZo/xi8aUT1pg56BI2V62n55umv
D3m4KZJuxdQBwZIOu9s80+gUszJc4gB/B0hiOtwgI3PFL4kqd5D2fvu7X/kzLVNmubBgqbSMXDdx
5sDs0miN2vKox06F2MU2EDWyZFl1u3BbOw1ZDMUnqE2wDJwddAvS0ol2RQ4Sot7raizOEoT8zWYu
1f2oHxeDYyq+cXZKwni7KoV/5z5NuU0+dy3cPBhOwJUeuSi8kEgaRudDdmupDDY9vP9SXEScIUOF
6ejLakjH5UoudSzPPpMNsya7trlLMQYPKeeVIq134UT0PQP3xqb28OSmNsOPiVyrf4oeysNA4nWm
uj4ZU0drI8igVOfSDKK2hIiCYeCW1PqVNnQmgZIypETZJ4G18n8nyN7Hd8CUtjNBqlKSWLhDZUSy
A9xDU+Ew34DhKN4wbh0jiX9tvZVLUWmBdtpyp0FBCJam5Ixk/C72ZiqZ/yJre7WCx16FnuVIXORx
cvODNZbwTo6q7UaMDC9cDLuqpC50Y5LJ3DZyLc04s3OX9aoaYMJAxRtOXuSK+Tnvd3+L0s0v6c6y
fA63WyC1f66ZkfbD/z3/B56pCVKS/l1R4A5/H+eu6F2qeaEf6YRk4cYvEfV/eOofDonKuvCjz9ZA
cQyrc6mqN7dpU7wCVWHL0gp5J8OPkzlk/xOcSnSqE+qYKuc8TurSBOs/5/y6ojDKfejdhPRcBflE
xZq3BujvGmaYc+G81CXo9gAf0/hSFq9BO+xeoENb6zc7dFs2VNvgALrTGxL7ivZKLfEaOavqm6EU
hqgez+xKFZ2LeBDjn32KbuU67EHC+rqbNu56CuGaOL1/F2gf4lURXswQKsda5MyNH3sqbwkVsf6R
sZh6NMtSzFZa9/YV97VZAz+XjpgVos/UaO0kRrOYWqqnbGK8TyOrgQFElTf1HAKIPFwfzdRjIvvz
mHWYkT5c1F5Al0y9MBbdbvlXgMwhHuGkCkhsVAWL/Il+fpFEeohgKIYIxxbymWGs5qozIsl/BXhu
wYxh2llanHnBpDzKTH97h7J/ongcJoeUAkTgGHqvjyw1JCSw36r7fhfYUIvklpN4nORip500cNCy
sGnSVJZzRtFaaGX/0uzAurwIdRog1foMfhpnnlfT0BXe7ebwxsRe8HfJw0fBgAJdkITJED+XzLMx
u0Pz++gwzsjyKnZw76mfu4O4s29gBmaU6CGS96mCd22qid6ubRqzjKRfUN4DvVPl9tUCF0XJZY7u
I5knqTehSAK/oquztThRRyIUFpafI1C+ZgomXF4XB0GY2ByfAu5+JuoRd4Xvp8zfsp8p9yBEHM7E
9JsVRZVgYiJ0GmxOxTfm8rdqCRv1OrnKCHiEPGQ1ElerG2hAAjUkoqoj35YIqJf2t4VaYCQ5zz9d
9xWj+SIF7KyVDXVSlasgqPWJliaLwpmJmuEBtKFILsNQtNO6zXbJqaWCr6CSeRlklofgItU2FM8/
pGQ0LIkCAYPpyoETXRcx0EmBv5L8jmvz0d2UKnneA/Rio40scCnL0/nDx63pKbKeBMfP4pFAh458
K2XHAYm/K/QkYwsSNhv+wX1BN3Esa35FSz7yU/a+WupOnmHhAgarDX1SD9hiqH4e3IrdSHn0bNO4
9Z/75kI1BuD/9pPq+hdh8Xu7yE8B1UPxmXsRxvpuCnQ77sfd7gGAn3LvUkpGcWna5MhfHf/+vYkA
uC1jMnKoT3bchvMdxbPBAJb6JwvwCDPYoICfBG9Q6ORzEayvjcXMlWixDjxUYSOJ0bFnwy5wFVhK
ChalHb59hvPhvC0cIN5eTOAOgUw9Zg9a4iidtPfJsgSpHlUTU+NoX2jDugJeugCcSNmn1InpTDbu
XXjfTg==
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
