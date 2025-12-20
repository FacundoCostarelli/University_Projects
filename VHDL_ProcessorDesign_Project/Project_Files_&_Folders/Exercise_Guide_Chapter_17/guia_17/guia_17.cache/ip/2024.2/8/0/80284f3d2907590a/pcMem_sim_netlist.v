// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.2 (win64) Build 5239630 Fri Nov 08 22:35:27 MST 2024
// Date        : Thu Oct  9 15:50:08 2025
// Host        : DESKTOP-38PF9T6 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ pcMem_sim_netlist.v
// Design      : pcMem
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z010iclg400-1L
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
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
/ZL5eQ==
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
