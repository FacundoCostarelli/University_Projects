// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.2 (win64) Build 5239630 Fri Nov 08 22:35:27 MST 2024
// Date        : Thu Oct 30 17:15:16 2025
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
OCw1ur7opam3yoqtOAmMxItQ6FYClGokMXcmhX5ZnwrdxV/84OrvSuny3v0eBR1KAqVdujNRZ787
saG/qcotiCxhyiMi1vsif1krlPSH6VizPaTrMOwDl/KA+VRvE+KlCWbVZS81vvqOUUSMrfdzESej
jkERybZsdknK9ShznIHeyv2V85gE0WTwYYh2e9A6DMn+3KZDQHuKRcnD9VelHo81qYa/2JBIOa+i
ra+HZgdy637d+MdLkA99KoxnvxMw/Q1fIi/5ZOlUEqrcl3tesFNYaU0V/3+EvWLhvr5opETL+VEF
SWO8glIQLWGyYYbNIsIqnuZ/LAgQhx3TrL5WEdyd34Ar1biGNXERXAAXo6YSK72Wjfqi+DZUA8nt
vc8eJ7fJ8223YVygy2hgrSKmwvJbbZXYYInSE6wyBElo8vKBjZ6djZwuT1qZ7MvpehgV7FCQiWcb
iH4o+r1XsZJINL+F6VWyjj2llTjXsCseddqmtdmuWsU5Za8kDLp3ijH0duv6AkU6LVE47GTiA7cb
9JG4IEokbtb1NBj3k7XInJnExCb9xnPfcYqdtPaLUx+N9f03k7RH1tzEGxXNRS25Vi88v+VXNULR
nbGQ9wbns3bzElcSNv7/98/NrdHp+qwkl0QC0Vk8ztKApxW72FEvUBPLWI2Dfq68v1HyW7fYo8Jz
lKO5mlAtpPh6eOJLentikXjOGrDJqms+/VRkBmRPLHvxDM3v1dQ5d7e9YWwiSFmdu3TajzXHNboq
xpITlQGZGaADSamBLU3UyR4xBdzGUJQjI7gVM+TKuYZCTBaZ3l8t3/qNRQG1s43uWgyRvmSGVcKR
Scg6FmqbWDq2l/NUaI3cqK0tw9cjiLFidDoHgrPUU7RQ1c5xqlO6td34KPQB7Qh8AFFibMk8+e6w
fSlgtI22/Kq7ZJVcLAOoL3PGMtIofYBlJFkEkqG+bOyEIsAAJiy4PJ9Wxfve2yYFMX1fgMVG+FuA
tedmzMjshFG2+cS+ns5k7Bd8aMIHPvudHegNkz1EKv9zP/kJ1VqLm3P2vz8nmVpAJNmSBF6QZhl6
kYhNhXYlbzIGR78Mm1OuGQLty4R0ymuJv/kCZ+6a7txa77jK9STsL+89g3axTcBu/Q8axwrD+AmC
mqHEglu43Xh2dwUwhJK2YE8yMbgRlxsBF64evb+t5mQjJlE9Ozmbn9k7JImX0slmRjFGFQYWb0fS
abnAOIbAl9LcgZH/nngkvA+xaQ1TR4L2A5AiBYKRxiyMUWSAFBJR3e14kMcwHlVYNMqF/P2Yq5K9
qiSTY7ODI4sWY7wEIMOZOh9r6GxsxTNFvC6paN6R+b9X2UBxWd2o1amNIe3+gjZa+P4FVlYNZ/ap
3Cu7tgDK9imR77Q+e5P5VTMkm8Hg4Te/j8kVwW9bQk7VnhyGDU2Io6tFV1cDjzLNh9MNS8FC44hv
4BM0BlfhY8325wIEqUpi3MAk7KLbAwpIYeg//tegKY1CLQ8vEsvxeAwxiTIF6BQhQ61qg4W0fZ5L
DEGVvmomvbgoFvtZF7cocamCNFRoU+kNBTsl+7AIdU3atdkr7TeACf6x2yqxHlsDcLyxC2UYm0v2
frThkLU9fHUi2BEduKHClJ6WqojfdsvDTvrXz+PN66atEv8UoH54zmHOHOIG1HNW2v1sSuWHYdxk
zPLKjpOWwFjs7aYLumcIp4hsYwxl/z7uC4jarv46y3w5cBitqzwMek7tNDJNXUHqs5FE8VyvDRGh
xc1nHT5sNuhZn0ZCpAfX6JgZ0gDnrm8rXDcsWunLqlkQ8PVuWJyZ9x57Bvc6x5tvWLobnXN+nwhy
JcPSv58A2h8HI5qY6GQaFlWv049eIU6D/MtyLK0Sde6m6bq2qzBLFYNuH+Ot9egAkys7/DLekC0a
MLjuF6m6ptLqeSMoNQpaS1eYS5+O7cxwQG9ovDvxbbbbIvU5og9cdAytYu+/f4J8CnA97clJfR0b
A8JvmHSudOINZhZKwPh3Pl+UGJPoglHIF0L5DTXr8R26f1thGdSNvWZj6YNwl3OG1K/8K6V+8oRF
AQF50DCIs/aYQGc+z+hLpu/FtOlLb1GZtou8gD/1teP5eBjq7U6DDcS4KK2kXmvLteZzro6p0wXP
hsihwZTyeuBLkGTxl0XHUFISAueVexUy/tjagCsxjinRlVylYUxFEGndYa8KRXqfTjx0RNDHUzK9
j0KNoCywCSSd7hGHMINLM/HwmTubT/ZNdkBsXxFLuJApnGgiAIeYBjZ0so6pJDFIpFfwhTywvoWA
6Bps6bY3Q228v8K4clGVOLnmVXobgogp7SbMcVvPw8SyvOAqY5nJBa+0KUewCUH7RxDXJmkO8h0w
iU+nBtHwog2mbwv8U33vEjp0A2wa0Q4hsdcKDMzURT/i25jrHkSghYX8FeglWswtRJyTXJt3ioLG
ojkFdENNrmS7M5ezJrwBvkwoPd1D85h9hLEK52qJiIMo3WeRigryRse/4SMIKhvRzGPm6V2hXNyO
+btrjQXd44uUJeWnf3nrzJXaJ8aH5HjgmvUTA4mobRjrYUYmC4uF1m+5HHGtzfUS34MbC7b+/2VS
HAQ19SoLradNlv0ifGZI+ZGPaEcP00JGXRUxJmg82HwnSsd2ak/YxnY6fBWREtcJhrsLLsMO2FOD
DRzuautLX90DSgjQmp8qd+QZwuXJjYKyqlqhEGkrANOkef/dTBMhnEWNAuFsyPDbGwFt7kHJHb1j
hmpLp8zMxIviAO7hHBZY/HbS16Y9I0gE0VGaPkWsz5Z9Wvb3I25cOpdBp9RjYqE0yxnK1pQqXexS
UWJxlHqWuoXZXppwvn3ssglGlX1qLXBCp/rO6orJ9WdQ9sNC2ZhwOffJW0crV23lCf4Q9FJ0TAyA
J5rQ12KXo6rv4aQMszVDaajatup1b7QQVxnTQPRwUHpx/ces5BizyjpFsBJUltEJ+asTFOP1cRlk
kKp4SFP6d1mukuwgVqcgdJTWxWO7iSk8h0GgdGKFKY9PT1fYgDf9pw10qxugRXAdO7DLGOXKhK5r
E1XaA8WFFKamFLFo+G5ARXUVd7tXerBj8bvjSAbSbnNbfjfTiSJa5s+TN5hO3VNGhr03BzOr0pHr
Wq1z9z52yp3ZcFmXnDGVELoFOplgkhJpZoyIGWT5xMH8JpaSZpsIAhTQD875wUA79jUdOvsVJU+e
U6ZpQoL6xVz1Fu053e+Azd+IuEwW7hPf1edkgVF6uK8pbjHA4I2sro6xf3Rnzn0wDyZiPlpvGq5Q
8kim2f5sSmdQMF81Qc0K8BFOVYzs/BswTxCgCZsHNwiPssvtMcsX8DK5AaEjUHAE5qWfvjkb/6jH
3bZHGRdjW9XGgjtQPwzNkOHT5+BWz+hWVTqlT9dSHwnUcz/s0fbGfsd3ume+FVYgRUYuiE2u/hcF
YYYDaNNCCz7pWp/uUxH0azBpVJVF1HPO4rC5Q7d/GV0c9lMvjHEtF88rFJNn+0Bb+XORqxyoLNam
gNmUWWJafixP/8+Ta6XImssKpueQvuTTYafqJT0oMY0LebAH6o9QsbIhOWRwBQWjty29VKBmSP6p
CXchtuIG6XLOiRq9UnBlrvSboAb3Tezm3kseaNonsZCAB7FYBub3PTlf+dVktTRm71sZvoibJuew
wVHvxNglM65IHsEyOmn2xOTNexKtCRlvvlBuzLBUDemAUht+W6zcpCgLoeMvURNvp0Bn7mht6Unq
S5JwEx5ZMFkWTfVneHbvqNALkAE2Edjx27IEonpA1n5iddJDrlbtGAnOy2OOVtM9/22Od6b7wKwf
CGH7eQLO41+LWR2S1xKF2Eat2FBw+FdOv2dGigAVrIPGJ/j2hniwLv41AXkccCZs3gE/NMMFNx7X
GT+YHKvmFdlDDxVojLCJT1JosZKCPv1HZymxAUHKusVLzXx6zSloMJVGI6XfEFbljzFIulcQWpHL
aQZfOFNFFtXDNvirl3sVekbA/kp33SQ+9eR0tsGJeduuUuQ/8ESxESw5oVE+VZwVq6wG6hkOjtQx
O1wop06i/oUxalQAIkKAhoX3qxrR1a36G6fqqCxp23xkHsiCLht4OI3nkA7c/evB5ngnNSWTPgNu
GqNcV/aLp3IphOeKFHX28yj+ldzxaE0GWUbf9Mm5yyt6BYHJtm02/7XELqkwL0mMyyBzOTh3R1AW
EsXIDLQdLa5Z5ul7BNJdGftlyKiv4cgxmeSQ2FrvjotgvQI0YBw3oaJKiRmk/xR3qH2wtvi9Z+Nz
AvdsGGJZ1aZSfAjsWhHFk78YdXuD0Hd+pDuGK53eC+mKCHdMSIQ9efGC3iy+aHgkffoEBRRSOVU5
eTMgIQdwn04sE2awdEMQOxYJ75YwYsggSDaxVMxTH9JE/mAnOFJDBVaUBPAtnfpNal+m90Z92W7g
kLmSiP6Bfc9EY5ecl1MQxvYd8H9yXUj2mKa910VtP9WEO4ltrYr5s5Ko+Y6ClKv4+Fxay8lsjXDv
GG2oLTnpUHyao8sTGp5nOrBBmGqfZhduUsLBrFJZgfnEtxaAlStAmAgiYiDOQ67wb1bzF/4s9jmp
jO3CM+zuE/O4G0FPlBmnuPItJ0lSEkQeCWXGsSFw2ByueajH4sx2VeRLdfAPmhRnoI5bNw5iyzsq
hL6wPfuLXHvbTTTFD+HOUlHjESXLHAgtcuAu/BNZSwFjytCr2y0OG3lq5hOFUO2xMM0wAP5oyCSX
/LkZjz/ni0ordCT3SOOX/86yfb12LMLVpvNblwzCuWLiRrJTKAX6v+PC3WvSddjZrvqbuBQR4cAH
XKCvOtbKFd4ZbXyt5zTKgBffldXIMT7AoF+KHvNAKc4s+ufgaywmzdzcwUQUb4NNNer6ZgqhM1/0
t/gi/wkXpb0ftAiRoPrd5j8xFV8SzdP85KzxPRE0qMLzvVT1ebU0sbHvR8DrIiN/pk6fJeyQ+2JB
EpfnO0tviR6ZrEWxZmxiSC/V2kBJJR8zmuTmVjLAPkkS1qhsxvJw5T8VgBj2GBPhN7LhdqdUR4et
J0mH6hKtWtAwRQi3N6k3yQo1pMViRQfUpfeSKfLXmk6gfQQ8EdN8bqx3zJFhACWKw77tXFTwrDny
vcgCQZIQEqwEb1KhjdP0irkkPy9dfhwI9ZXcOWEZj2/y88gtJZZMn9+fkNp0FOr0FCTI8Fix1hhM
J+w4BgSVvgGEB04OQSojvhW/ZzQpVFGCqPqXTa5Zynn1U4egW3Z0jjbic90xNj5lUCCZAYIks3UO
kvvSqkjsUDQUpTVCJ9X3YxPedEV00RSOVdZZjkQc5ec+cZPzD2l5FpayH8oP7fvR/7HN/KJI8txq
sCVQPivHqv34SMQBwMGS7d/Mffg2e4vNVz50ffXr8XBnxMnb9wKBGlys9vi7+r2x79O8O+h4MMkr
YXgGuH1UgEbDiE/MyqxA49gMlWoHwOJU0bjN9rCxHJv+FElsQCN3Xkr/gOPOASVwpKjiE3ri7uzi
iv7oHoD8ZHkEDG1w1JYge+j8rT+8wUmBIYcRaNiwJ+KycbuwvmcDC8hQTy1xv9VnOdSt4hmJ0CgS
WK8XXzUgkg8HoKOp3mb2j8YilPF+dKgXgC6eB80Gun7jO47P9fXSRlU0D5y3viOKvWphxzLvcWEH
CZnlDLdMfL2iYi3xAaVVwzmK5Ebxjni/C1ciYL57LAWoMzEjxybbrBwd8PseGdXRMXzbKZnpUyIv
EN+xYrQGyCMjig/b55z5Hg93IGxo4rQz2IXl+El29fBQxNjcnaQGBs7SGAo5OHMedf02BLm9A1O9
Z8qW6uBaBlCYyK97igDbg0QMUuoDZsbSSHuJN8jo93/Yz4Rl98vv7uJgp1BeV6L0ErhjNWDYic8f
9ZIv1nxhbusscTnWdTgZIJ2Q1gkyICDiN1/Wj7Fo5Sh1EfllpvlZxC+xp/UG/GyrJQfy7uvEIwxm
wJ+eRdZiSJNEtREtzr8erSWLay1i3ENh5PYiJ6MgoPjWh+8lI01UFx5aH7YUimXvPzEiJjUiIW7r
q4TPJRBWPoVM5T//Gcm/RJjZwJTH7DZqyl8L269o0jACghwl1BICAqNuEDq6MzqJ2+D+cXWTsc2Z
LXGjhYu1bL5C+qPime9Z15MFcnOK5NvM0mBEjFY9YkQymyug2C7qE0N1u+G0O6Ayli75DGNIqPU2
dM6RbCqINHqWeiwXjli6VpFlhbpwrKExJedOk80Qw+FzqP74eEtFj3CMMK7iWrhOOdG8bpOvZt6Q
0WFGeePGBkKNJ+lzoZW4uN7V0q24iwaVbFrkv11oPRgqNBKwZwPukkjcMORh3xwL9O9VmdQJVhnr
3oENS3nHUVZgAhp1Zt/nw638fEgskyK/P4PF2RL9s07Pc27uVUeruTQ+UTBScHj4BGX8dAupoURb
bPymA+yAR2Nc3q5LBZasAYRo2cr+fOYzhfO0cmfDP9tjeWvFmYpwGU2lkQZwVixvS5BIK8LEGnHI
01k3HkvjclTh59b3/SL8HjzPkeXhlWnbPE5usqklPYqr7q4ZJUpQs51WsnJdN/neaLasXr7vtfc2
6yh3E9QOT3s4y0kRcNqNtzF/mM6cux8EFPY/6CpJ83Ut4umNF1oOXRs/jojJ8BXmt6mK8rUtiYPt
bfIx4Q/OLEPgv4JYVrH5jkGMFP8/oVgMT1un7qK6KV2jVkw9QUh04gHWO+h/U7CALdy69RrFK0ct
2l9wUSRE/6NlKL0sTI0NcdvO7MuMdVRLyUqFYFvWP4LRccte29yRgBWA6Pgrlo8FTosqlNGLcQjx
puj9HYJYlJwAlrMVnTzvGw9TUnPzVssJDRvogQ5IrUm/TvOJROTHGm8cYvWQ7ceUI7bJPGRfa96T
fHJUeEEXmjheCZNni/jO2l4rbbxk6rRLyayBSDIELKLymgLxUmXpzzScZxV0DI0967FMpz/Gs4v1
RzmHeaBJqiGVd3sOSLC/vBnkT6K++HsT1PAkQkAmeVt4EZc6e7XkJhGmiQxtziv54tm3jw8Ir4tI
K0xx6DAloFr+KlwADRoI9x86ZPMm6d2IZWfQmd2AYcp9RjYL1/c+2LTO6aEyXdFnxLaKpwG2Oj6Y
USxFE2Y9NgD66qgA5I0TUuHkutK6xO4UcuKhowhHg7EUG3LOrxvf9fFQVAFiC8S0kdtGbOxVt2mB
6cWh5ilcTh4qAfZMtkMR1mVQh87u0WjOm+inu9M/RBAcnFcaHamIcifhzaOqv0xKU9T7a29GkUa+
SZCTcqcOUmYjDKLNmI0F30oC9hM8gXdrUMThe2K6d+7QoslgYe80fUr6BCu6ofloDAw1pmFnAob9
8UtgDW3v2VVRkGY0OqLRVASlTR39wbz6XDYHSdmQmAejY0RRZr9nJjRibaM6QXjAJd6YQp7DBur+
eIk7680XoUfDHgtH12nQjmARH2EYKnuDrTBGyoPMEGIZFlLOTxDJn3Agn18OABb9oXyClu2UwBOo
+/2JFFQWcbfS0wLja/PveN7LPjQr0n9CADqt55plVRz9zl1sWzcsZt5V4/wwo/F8lptevqTa7SQZ
UmR/46MjR1Ie561f/sQcH/Rxhmsx8f5QQksOXFvUdnsr3V5/Ne3WM2BFkPgL32XGss4wrlk2bX2P
uOsJB08x3v80CVdKxfFMOsDgTGUXzbAuNpG5j7kl4yzAMIE46h3bWUQrF3b1yRG5VTPBoMH0hwJk
zZreNQ5yR2fDWZjvjSewYvjpsBXll6bcoK2M2trKC2ILd/Wlk+VoG7Xd+jLJwX8IDKYjsA4QvUWP
Tr6PIsmbd8v0gY0JzN+mlZtLEVF69x4dY+Zs756l3xMnt0NQGNyH6LHEqYnFES1mBoCwwDsD5VOK
lL4G9FH+07hZUeWwJUvFUyJJpczUr0bjQ2B36fy+4IizpMK6qoFpfrlOny9Aevpv8B7VRItgql9b
OURkR7lJre9t8vMZZmGGpvuB9ox/+XWnYekzvCXIhDsg+ZtsSTieofy5fBe/f/5U7Sl4JObD3X9j
B3pXSn9DJWMEXKn9n1S2E94qQWOtKEbUvWbTRkTkMSWxmDhuAIpLPVIFsH4+bXfy2tcFJqAZTHKc
eq0HLOY1uGJZxX3UJQjbOxD62KjvziAKdwClFPLleBHXoDdKKIjgASFPlvv+fO86HAbuZNcyeu9C
TL9hm/EwDJsYGsbYQikLNUL1jzVpMSrVNU1NYTzDZQ7n0wmUIqMocngU3nOrhTnh9PT0hlJM+UU1
OLnFXQUzjwqrps4SVpBFcK9Jr9RjDw+Hg7TRuo/E3Is6ZNZfDl81BIYy4s0a5Kyz191tPsoTVlFq
EDwM2N67G+OSKFvufkKsUpwM/cpRvE+ghDVXv4PNTnQoqB6qzNdisPqk9rl5UmhmrgmGS16md3eV
pJ0EN9pQPLU6tbkXYYHFXSFjZtcmR86iahrpAlUzcufwTcVzxkzyEphMAzHIhPHHH0ID3XrnrRFU
z8K5LLYB2G7gH8jfn1sY/RzGuXzCIM9mOs7PA5CqYmHI7ua3hyC3lxzyjCUxitEvFwjCIMzVedap
14fQryiwycoiCh5JEOLDUxNUEZQcp0NS41Sve68viWtisI99r5mkREkL4Xk8J/IueSxHYNpoFW3X
ozBWblky36uhmO8EgJd/NKwFjKYqnptNSlUugnoMtzJrmLUG2NNMyLWenrCAxGnzx0kNWLfHDDRk
CgPIIUpcWqfVj+nEGBYiUqFcWK5ay4Dv2EPp+0HDjOCN2zcZW2izuQ46LXYyXKZLJZJMVzh0M4yD
q/wmDK2ltZp/Rz8duhT3f5StQWiHNVQy0CLUvW7E72IwIouQhuAbd1eID3E92UwNj6foyHblCZU2
IVpJXpW+3n35zKXBYKNfWgC7AMrZNXjcX+A1LzVjr0wl3uVdWjD6TZz4XbdcHpQR9hJLY89tGaJA
18QZcesRCd63ocADgKC+tbAmTFwVl2qs/3s6ffV+6i8aiYzbLF8hnbMe/UNZoVnOraUjQrgh7Wgp
Dse0BrVYkBCt5WIeKfNYaeD0L6MnQ4hZPBRetoB1lWSwKiETZirVHSOmzvK6YAqlOPsOxtMINaIA
cbCW1HngtR7N8dMst577K9SGqekhHsothgNNhdwabeuawlEjXzTCdgxPx17ydIvhkX7CSd0irnNJ
YUIfWAKNZJ+LDf6HFW8y6o/GTiTYbEKRFoMTtoCp10oV+t+pq8VOD+UjYs/4OM4Ae832z1t78DiW
39G9PCu6OfssNRVFdyjcpxOwr+TGiNSws8DygCOj37AkctSFb7hPqA5gNbAovAFDpV91IryHkE0b
him7ULb65W8CawNToYhj0DPTTGvbgqNmX1CXX0sCGHR5qWuJukF0IPrXyHdf/qXMmgq+3VHHRPG3
b/A19tWLlkLq6XNoPd8FPappwULX+pN+bS0mthq8P9c40Cgf6MlnJqt09KmdXkB5sTYasm33J8OO
0OscSbFr2u8ABDaxlTIDTIjGc6J7C5/VgCwSW29vwOok3iJD/NSRiMp5YLWaYnYnPoZABLWzuYLs
oPR4+Yve2dtFAihaBAwCMm/6isMfEu5ezcWWk1L7czTqYhU88IAupD+Q1w2Fr8M5B1CvdtyvOGG/
zzyWKHqTW50SA/BaUtpBYs2a0OEoczOLRzSDP6AdWstUY5Z7neCLaJ/L+PLr6/4SFjjQJ8s9XbNi
iHZxcqAa6BV0jwCyi4bZ0o6TIIbLxvSlqwM9B3Z9fd9w1yJuwJ9o/DLkkt4GcuPZsNsWub+M7JpY
9ImqVL/fXC+JhUeXrjjW8EekeKt/hGz9VHWUqD3t2XzZdO1p0+LJWAonxvlCS15C/1PtByHxFHx8
QlHvaNLi7IOCD04TBIgvdFxZ2qeN0lAvYjiltuEi/rjCfJlSPZOQg1ubcuxKklHj1xcCmRzHiIZX
QGdhNE4IchpcTDFeIOM7GCKzWjl5DyTzoDNrfWyh61P56Tb1Q1L+5F/tP+Ig5LxId8Qs/emUCjvC
qeUx7/Xb8Kysh5qq5ywBDDoqYebv9cF1UNWpqlp04IVL7OHpwdQM4kBpabGYiW740d5CdEWiiMQw
j8QngNrOQolu9Sx+SokZ1Wgc/Fps8S5Be6mieMsGMhxbT/T7zVMmUWVcwY29Db+MrLJVjL7Cv5Gm
2f3xms1CEHhfgVtPxfKvGoCr768JuDMW0bOrspDVf3CCa7LoqtnM/DtFGqBIpjaMRgN2MpYhwjW6
GhmilujxtVPMKTWH41/KF+C4VWhIB9yBfTDBtVYVh1Y/f7nuzBDTLu+IP2pStTkJikgZ833r4rH0
4bAsQpJP2Rb5SRY8JL2EtVb5VptNG8pyeBm3gel0tuQWCuNtjIn7nWctjhLDa0aAoc2tMa5q4eyQ
MHnhbJC/qL9F9MGCiWWDgi1u6AoV4J9MiKp3+ZSfwrMB1p808vuxt6eQxtd4dBauc0oLuAzff6WB
87C4hbp3BNiMXqLaZR7xU7JxaKwMbcvSzDe78/weWyc1sOTIq+ojp+vx/xARtqSaF3GpBWwh6oFr
NPoC6X2yOpor2i9Ygv4t343+LNrV5V5aBabfQxNXTdJnACia7OILXAmQLDTX/l1XbLkW0y7OOiCg
QXA+ufRYOfchf2WKONjIXnUkDqO2CCUJH9NwnNTgs4KcSm8O1UQ03YhWyZYOKfepi5Wko2mEl2/F
JHx+qzlxBfwmY6AJONQjKloxCPc3THo8y+/3emN8iIUrNU2PW9SbQ+b9iFDt2RuG9TUrJ5L1T0RL
EpSmX8hkJHCaG2C5UDbUk5GIKonInlKT3jZaGcD4kjlJ0VZwEi7/K+NoWM0kg6KqDj5DelcDcKbZ
GpZT5ynNau86QC+k8CNQqorU+GC877T85oh9yGwX3lU68VNSrlpVI+0bO5tL1U2THV1XAh/2rWBn
nMpfmdlmRlemhfFnrE9G4MO8xvmv+A1yn2u4pUU9B2D0c3ZaECOZjV1fQK7wqEd0XesXqC5SVcOW
tt7cZTqBup/4t1nIbYA8YwdWwwMV2bPiy0qCSyzX2up6InRG+cRIHnDCQ2oYOU1pgLO8QSi9bfcy
e+KA713KjT1cl965G8IBLXvICFuBx/7fuAs+KCy0XVMNmmeuX1xPHsWolpvWryexEtDF6ZG7FkZs
RX6OvM1UavKmLbODPXUGCpef2yJvef9DyFKwBsd1RSCfFBzyYi4T67bE4aJCm4W4oly4EWXbFKqT
R5O0hhP846rqNZa7/5tOQqkcQYPhbS8pm014nNiDx8Yhg5fUlrsYYBtIbo1FQYOWaQMtNLB22n36
lgbb36p5oJf/L2lS125H5wdX2jrqybQoyZFMzPUc5t0R8f82IssVd89chNtk23+L2b0LBBzT3X/8
T2RQHCWzlrdx/FlZTX+hg6GjcoWHg0Z4nLD15Y8/mJRJKufP3CchH9GSuAAzfIn9TW19eI0UumP8
ksXgJ4XZmVCdOvSL63yCfoKzfK5VGYIMCDEj/agJxVGm2DkIuUaS8ouJc9FHKieeYTND1oI/FiRs
kcSEVfQ+Fpsx55Ur1gWdAE6GT4GgoDCsqhNfbeJFvuciZhoitVZ2+EbmFx4CKVfCcO2vA0lys1PM
WEKWCyXXZftlKlQEIOZBMn8K2yAXWcOBVzqYcAqEvWVxGYpcRCjK/dH/inzEfKrNBpUUaMcUxv/+
+ArKwj9p+hWgev04L+wJhk6OdsIUfXTxXw/dwu0IG8+2mLId7bFDAcpybO3zFuTPto1pmmqo2ced
d9XMBjinO1cECFCHNMRejYTuLzbV2LalGLOrUzvaY9BmJDpX1bHgM5uiNy9Pn4sKqD9708Cbym2a
Lku6zTUHljY2D3rcMisAJhcZhXOw9UNByULDEcf0i0iswnf3laC5Qf0vq3vOxU2Nc4RwC3zDxPuM
Hn261pb0JxnFiyj6qWqVNpu94+weHABLsBQUvPyl/tqLS1TCjwNJq2zCRVheHJL969FmrYo+tqgk
/ZGUArS+o2L6jDLdPG1FiWp31gsEfuty2uPuEVoDVcsNTqsxgDw6zljVvJNBdooZVobGd01AOwCn
mW4LOsZQc0+PtSPcfzSUASRzOIVX3aEyu10VufIDM22iq3RPR6IRWl302HlP99GnjeT4BJU0pEMP
Mm0/E6WhIVUhKdSSA2ZIrMLK4ax7GM1HH3ooltEUSCn1V8nUgOvevxCZolp/VRkSl5GD9uHBZlL0
MN4ASLuVIazMHw0p5E6aJQkBou34qAKXyz2nU38n6wQRU5JOqIyu2Bs3wv50He78LAjpeOQx73SS
DsB51duH78QAhwJJXKxI2gZyXHS033T8z3OMXheTX2eFdh4FlRqQ5+2kvSEk5oCn9xV6daQhEaYz
DTNlZxNxtsnM9UYsdNQ8TJvzs9ebW4wQmPph0CmfHpLhhOdUvl/5AKV9VslEnmWGv8WS2SrxvgMq
YQJCgSu1KoB67mPI2xYI6Etp9o8432S93ugcUL3dPvD+3UK8y+Etk7XeYLoslEt/w6aIM327VbQD
mEBRggjET1l9/QMTYge02hEnpQdGOcseBEYl/wbV16urPaI46PRYWipKnHoFtgcrdilg91l7Ge45
+mxblPbfvnxEM4JfadnDkx2ywPbrqZKosMBmk0lzztkxpj+00M52SMUbPpaYxm6wYWurYeB+VJNV
pDkWOKhAzOrr8S1ZhUWHExb9u7/DGfZt2JVWd4xAjS8zd7HfhhEM7NQs99PpWW5QW/lFglPzcSdf
z+kV0WepZMiYEE14n0JYIWT6QySsODSkDv1YKXVREVGBK70hZZTv1umcM4x7Y+YXMzNKyKBMNVOg
+Ssmg5HbI1cI2SJCmQ0swPTnSxY4c0Sxyju0IA2tn6y2D06Ei/AZy+jwRj2xU5pcs/oyfyfc3uEF
byoPZlSMM9fBqToefcIHjmGW2uUlGAMBUONrzl+RAqGqSozXeQ4L9pBQAi5lMBp0stlMDaF8i3+j
U8btckTOPWJKDdlT9Es0e8v5hzTUKEr2pi2pqJH1vlA3kQN0D3l48B7DQWX/OJrZmZcW3A86Nohi
81JtnoqgEa0TYzJwl7G03iQjzeUBAZLuAeDCFrdMefPMj8f0OEQPBs1azOmdK27c/SQObRPScHcJ
2yhohSQW7uBaVgT5ApqP/vYOIByHxaSpcxJjJ9reOFcLuGBVWRO7qYzogOWiymoOqu3nB+QsM63b
vF7z6MWqOAN380xRQYSHV8FacxAt4zI2WmSsOzEk4+Rxn/FW6Dy1d3q2vlVvvEjQDYhFhrdVqFxK
TVQfEZx+tzMXTVg3R+AyY+g0EcsOu7NsYyDHrifLPV02rJp476HUrHK9mJetC9X+FM0ykAbGgAQd
t5mEJh1pP4cdNKEchoZckjin14r4wd6K5W+e2/OACWHtwf1UJhQ13AF82xNtGW8he8regFr6Eidg
iAEE/d0/rjWqPltsUA5UlbWcmQnqVJFmB0xyR2qy9Wl9VdCNkHXBzw/RRSrDTBHwEtXdmOnFQpyl
fchYAzsW0GwDvqcgelsGGWsxdIuxc31/l9jRgxrWnYemfp529PFXF27JUzF5CEV9abbYPL6Gy/0d
tNIgToKJWUhS5ybAdAYOhg1zBynBxWVQiJ94PQeQx8pZgWe19jdWO4LKjZGJx3vcVKeRYa3iiurt
BUHte9bkVklBN5ntnhbvkzUTxW24WI5zYnecEIKQ0qrurRnoLrLpL8lh20ub57T7kdmfejNeDIBP
eDH3sLO96FXZbpZyw7WZN1DQymqlmbd0xMcsnP2/gFHTpyCf3ggjhE4F02zTHts84Rmbb+lkW/1M
1l/J/MetBuoIKN1/Cwt2OB3UjGC6qaBanKnoG0vXVysmjMHaPOydrYa01REr0+Msyuo3wcOWI+LM
sU6MFAH8GYzmBMB1gLYN9LM/xfPTq84xjzwjZzImKaaNNZOrO0b6R18ku6jAfYIc0zJ7nt2g/4kp
4ygNHlJ6NLZclY8LR9f5dXDzcPgKry3zwrf8hNxmfb4KcKbGBQzM4ZTjgFfBO4+yC1Ah0lIBpNlk
rEw8naGmU8jL6cC7sc8oJPpUwunTnN8+jSoo2ogT6YAA09tOtlwLT912MtbH/MgcNIe9/RGZe281
rTDipzJvPfGP38MEleNDa2kKCREwM1/5CZAye23kcDdAKPS2UVPM+EvVOj7gJC8r8JIeCi1Ll0I9
VYzy7AEL+WsjPPQiHGK5CreoPM+3bARWDYPQZHWCbhfWKT8W0bGGcUXHsXB0E3zqtDp9LiyhfpOT
nb018Ig+g23tG8CP7YsGRP2eJ8VqsY9jl7zonPoCuiXsDtXcTXEQWrChtO0mV/HaZSSm41h49ZRY
m8NnHiepNonTmVrwwXuOP+7HV4PMH/xtj3MB8jJkEqQ3v6yTGcEEtGIjqMf9XmfKnIBWY5Sa2Qha
CpOetMzxVCmTm4OzdX/MfeFbyiDq2NB7FyNIo8GZepNyRXXKCBZe6MwubUXV1a5wamUytzctwWlf
YQtbsidkV79VndASCnV+H2PaXr5qzPxUMtAT0cRT+R298+R7geY+hSHBISeGg3YT4p/FmCTRcSiJ
0M0/fB3CpvFvGEx/7snMjx1S1QhlfDwMcsXaK4CnudQ+xryCKqQLa2U+xSVZ+ILIyXkCQ0OSXL8o
a8cIsli4VegCjwjGy//d6znapjplJZk7Zji6J5RvbEkMYfQRfUSK5Kw2t6ZfGTpmbxTGELmVJ8AR
eyr60KwY3T4ixzUYL8k0vzB9hkew5rRgmZTwAUpRAcL3zEJOZSVLUhmPZdKPA1RSy1v0W7C0n3AB
8cPGVb1UAqX2Ebq6jtyEgnr2Zldr19A6f8jCDUxudr9E9clPNDUfVJCuI9Ke//+tDiPrjMYMibS0
VpBIdVXi8fWWSsL4c6BHGxF3hJjS7N2zg1Cy6h5auFBE52/CAwxTdnbxXsScNkQwpnDMuNpMaH2a
feT04z6F6Qzimod9eD6wMYLUM/LgPVTK3H/Dgftc9Pk4834wWxI84wm6NeaYXYsSBddQXTaALk6K
RnsB8ppwo/+R6tg2t+gErDIIM5pqeUoPCu34+JUs5WEcDsnwTx9B6372k4C3y74hmrQnwKAHs0kj
61lQWBs2455JU4VyTxaEqCBAQF03eXVHBakYa5N4AVcxkqjJHTIAMMjKWTCqDesvW8+z4qdsc6Yz
GbXC5040VYDqrC/04Jb/J6mu8A7E/4EqOiTQVYM94l9QFsaqViryIjxAXTzHAkvfvG4ph5nTmxJX
6x59mjVBsAqOKShmUrx19v5fssLWAHGMTey2I9edxA3bVzHyfO4/AxbTNd9T86DfW2b0tp86vHab
8miibimT4e6NZfrTL5mGricTzT3hpR3POAvPlRcKG0eOhRaw84+R9WcausRC0KHgiNvqmSXleEgU
RgoQBY7LvwU5oKJ0eZSA069f/6QtFG+dFlJwH0CZUUqo7CCYwoKa043BpwhRmPBnvxVEZwSJ31ku
dJypvJRfZN3cHAiYZWj7zTOBqB7OTOL3501o7NSZfIBFFe3b8er6+GAvfJMeXaKvpduuS2jIeggV
LZDARNCxFWrC7YzSoQcTKuiBvj3gscm9w0Mhd2MZL3lvL0CKB4JBuE8AxnCFBcPaekpTBzuZoi6T
N8yXcvV/1uuLxXPM2JvsvCqSMCKgcv6itJlI3kByJKyKuKeb10P0y5Gu6MrH13C81fpfzsapclUm
tvWkecFIg8UPgWj4ZHWZcOpb1VW+zor5pfAUnrb8RPY0NHV7jZmjET/YEkHTGVCGH5Di8huArRoB
kr4I0h0aaNJmni5MuszXrxvUl2fReDNiY5CbREqwZ6N0/32XB8/A/4qKsbbxXOQNYBGugyCzQG8I
UTXpDyjNdL9Zk9pIJU/Ou0a8y6ENXd1cJUc2QqsZqvv+f+AhZO+pMmCwwa5Uqx3uYyB8HVQCCNTE
efVen4kymXzaoEq0hb8m6fXUCBn7s0aZl6ZoxzoiBjeQlxLu0pxm2rKFVkLqOsqxQrpImSUtKpEz
yog1S6v2hH1R3cS4yGnDGYlmMuFYKGAI90SQFmuRzn/WuIs4vFYs9olS53Cpso/uOSbdBr/iZUhT
3y3n52vvCLxZC0AimI6kpledXMV2wMOct/zruSLrilgteUVIXo3S1FxHpKHFNJGJRrQedwM4BJ1b
QH2NWXSYp/TRcOX+CMZVqes8SEQrv9dvjlb5T+MMAf03QTg0zWw3SLYp/o8I3q862O4pC2lgY2hP
zqDQM//VH6qiOu026yE3QVVCqiEOBjfx7sDEOraKsqC1ty2Of+DaztfERjXxQt6QW/07FVCpQ4Zw
jXLAhRk8t5YLij6FgghU1up/q30m4BcSVs0woC58uEdXEVaIh1vb503HISb0iAMDEEyOmI/ipkgr
PMJGSEV8jNwRJrfhBGN8u1ltKnVgVua9M4qo2c3Df7lv3H36kX75INp9yHw9lwTRIR5Ui2lcoAe0
cjBVqN4Yxa9uXxzZeyvboMbNzVfO1JMo1Pog2dFRYKw8fwMkNch/U3BJqIi1Cea48lghndowG3fW
1NxdtzxLI9NnfoBG07OkHU7Xa2qQLt5IvntVY+TnBLh9rN1XLp5F2JVlrN8bKRkHoxa9LPm0VKXK
HvqkavDkBrgVGb/ks9106lyWRdmxC9U5wJCOtsCA8MT4sIJSB4NfWe194xlWw/Iw2uiMFc7AvvTY
gWZ0GVPw53YshAWhs+cbvcrJLJlSeuwqc9FlNZ1vEf5+Gc9+Twk19udsLZA6m5tm7LCJHUTHjRwZ
H7J5rdetvAl0kg15+2c1TSnyXmgII1moHzCZ0neCK1pk5QhNKAnOmXjtHfcoB+sNikis/s2DoDh6
3fBaHDJ6CxxxF0bACXAI/+7HSB5Lvo2umCl0Ks0kPHaop+S2yssrbr5TMKq1RtAfuBXEqPCikFAL
msXy2FcACoE3Rlk4XrIYjLbMxd0WuPnHklQICXeH8Kl3UjCAgVineTIM5MJnlv/nxQ8TpbVOIke9
/I4Xb98x5A63kgtWfAhC4hGNIj+JoEtOVVHTdkhtk9B5bdMN/JLLDj17uGJHU3fy0ZU7bs+NYDMu
u80Yyumfwl2DHCM1g5iMnwczy3QRornJJMpvIi8q/Vp9l1922eETe9oz6H9Xku5ZZt6DwOKTU1Qn
9GiP2oOmtG5U1s26iss2aYvIvvhbfWflZ8a3qmzrCj4HLvGb1y1ujuL74mowhbB0rkiE22WihNPP
pR/EohUV/LmGa56PoEOnnxFtG25RnOV8lHIu+WsIK3LaTY2Rdk2rX8OkKjK+5DWWHjZCNo4X67+g
az7uj8VvXJt3pNLXx73xnZF+BFN3dCH9cWnubYOUFPBGH41WEUE1o3Jxy9bJ/MG4BEqYvIjik7Ob
7Ez7+5ZzS+76Q1qlBU0953XtArr2vpUmYwQxO9JMNToQ5/PHqKVj00FTpO6tZ0iSJUB8xe2qQFd/
7bzm6+6VzPUggnksFqJM+Kw0fGngqMIQeSEQ5j8hQ0A+HRW5yLfG6CKZTYU8cZyse4FNtjr1j4cg
xGc6x9brMCndye/SJrfRftJn5sbX7+HAVf43UuTr1SZXg8p6jDZn9ZfSmFAKHcXVrvkO7vU6GuvT
rkSuGrvsHTMF6Nst0ZBYoo0GV4f03DvnrP001SS5yx5fytySgk6kJE5qBKNZ6eEV/1VAVccz/qaN
5DUNl0m7D0P2l58du5zlqxXagzQHIDygo3Rmzg2cHQN8z2gNSJafkn8vmwh4X//41755JVlv827W
T8FZX+5ohEMf0wfRksBwY3XoGhVEFRNqKV7hpSDKQWUsvVpEvyVRtL6WKQOY9KSRIfSKBx/Ir5eJ
+/f92ydonOET3Z9CeZJ59zJoNiGYTbex2ghqJ8tKj3gQKBNby8KUjiyLuiApfPjZpmp1WbT3NmIx
t8cQefbthen52DCWtM9ZpbM6twirDv/qR+19CwB/aEIYo06d0brD5Mjpcn/51JeNuJOtHVoUNTPe
1bptZx1gh2SBmyarLU06qnN+gpCey+6xvAIF2tp7CpYBkZPkxw3dYcC5gY2NeOBsdgRuGYqToQNp
ADxwVWymvqPEi70nyeRJ51+/VazmPBcyB40pfVEa30xV1PC/p+FeIrJQv5JFbpmjJqjNnaB9aLuI
XHzCNu0GS2+DE5+N0vI/otEPidTXH+cylBgHCRN5VsFFdQqIsjykTfOAYmnLGWHx69zYOss23HNU
O0gQd4l8L2O/yIfXTW0tdPMsOmex0gMHlkZzOKe8vZyyDr88oTorVYK9p+8vR4pmj92ztQO4JcvR
4ikXx7KHOSiCb+Pg23JGttXFRs3aexxSKO97l7pLDoObIsjsShBf/gmT7nTVvcCPUKPz1Yh3UkMu
+lKfpOP0CzUVjVovMeAaN39laivVDrAmSJ2wvucXfOCVaaw7iA5CSBJhla930x9ipjWDJXNBOLae
RB1U2SUZUEVlkP1dV13QTy7/sH/ysxHcCYfdLs6TqLWuVbAeNNwZetV5ZsnAnHe7B+I0kUYE3OVJ
WHhVHCEt21at93nIeiCS5BM4iTAcjCMvFe4PkQvydiYNJibwgPgdJvPraCaiUn2NtV3226DzZDNC
oMggIeVOX6NL4ZmSrGLr+h18QDu5kmeTrMvcmSX2jWV4ZaklQgit8Fc7T42m+A9ADV/L4700fjyY
mC4QBH1bSgZIhjURxxU5vbP0iS2VYdfvAW/rBB3wYvTwOwqcjeqixnsWKaKJnb0mASOGWZLtnLej
WLceC0sSe4H7A43W+YWqev2SRZJkErxeOIZLIwC8a+lFTuOwAXMbJdiO9utMcjuofvrrEudJU3Fg
j7hLKYa0+89LhMM3/APtLrYt5Vw3I1dTkABtWgcSfQalxY9ZTe7FzKqM/0iwSv0jj1Nkm0trtDsG
j7fyRKXyL37dLr3eLncMazDV4dKB8ys+V5Pth3zthFYKMF3SsUErrN15VBZrsgFrq+YYp3MCZCvE
//gPB7p81Zgp+cdIbFruxq0u+Bw/I+n30T5YV4AJlyw/kh1tvEbcKTFhFXCBSU/tLspRPBGDrBME
FMUiI4hSb5n5n1rw3cwmcY2d697EhvBbjxEs+d/Y4r5mscnWN8hgSTm89N0F2900Js7pioBsj3D9
edPZbGo3XmM2rmdEfBDmYDDyDykmi9xk9fIckXPwj/EQco8fA6ApeiTzRFHt8oQOYuBpORkgZpzG
gg0tfmJ3GCihhFKH1ojLgTd6+KPvlGfVQB5txNkYf4N/4ImD+Ow3HvNKQelZX4dDSaAsH9fMA6Kt
0togTq+JYEu6Yx5WckLY9zlyDerdOQh60meglTq24VqofhCuuT2x1d+h6ZLFXEROkeVzlxAThs1E
3h57thmhWcRwLnzER86oMFYXmXx2inzg7ABBX92Gre/ae8nLKOvLutTI0LzP3CJzoi6Pcd4gkXs0
JmswuY+OOzMJv0cP8w+OY5XBaqLJJtdN6B2t9VdkYEXZX4we+MA1wEWbEOYSHmnTW8BkjLP86gL2
8s90NF5+mYoJvumArLqdyhUBWEQ3F9E4016Muq5oMsGg5paicrX0gjQ3ClgCr95/2PABPJ3yUTio
v2K1zPRV50iJZGX2UHXrefDB5VvUC/JLUv4UTmgr6bbCnQXhRdIAj0WiOsftD3+Qwf9RbIiOar2M
Np0MqW2oHEn7VXzXahyE5ZqOg5nhyL1V22K8liYKRZjgpjyC7c02xQV+EzB50x9z0aq9/isb0TI8
U971o/IIkrHo/m9j6vP3Kq92K/HoWgDdxExR7HeLdaSAG33CDmQuULc3E0jhRpChe+yWikogoNDv
wJgEtlRp55whCwpzCKJ/vjDLuXuXK4OA7ZX5hZLoKmg15YoGNoBGYvdRJzODwhbyFKm6toHymlWi
8iExit85RRWAvIoxK4DAOdnUkhEw8TY9m/Wh8DfZgI41ovZP1Gk15RsvumcBLZ3c2rNPn4y9L6aT
EPBXstEpFqnUaH6Ak9B79XT0ebV9R/WM1L3ZK5sV0oaZtWWUWQGr4ZZuSzjSbKIQ9v0PINqNBPZY
YSZAmORuMC9Dhi1vh6DACNXiPAGHH4EOEKIXPw+FVzFPV1fACEfHrVOCD+kVZvL6ZSGTJxO1o0Bi
UaR48+rMv6VS7xOWM/Xl+znUA2hgYls5v+SeL+ecckAZ38pkXpnfVtGbOgsLIQo5qFs10d+5tKwn
y6BnUU6IUCUfzH6Or7jAAIsLqYjSfqWkio8GuKTOr5incVhIXkYjyLZlkZfEB4kSFb0DbTjf3/lE
xWC+wD17u/zOSlj3DUsbtpJfvRMrbNga1v9C3/qIaB7Bpva1Ul2MzyYOdX+9FBJyHLUOVOxyziFF
iv+6MCPVVmcyAqT381fyWR8Aac9dPyDYZ9eHwQym4LIDtTOvHXScgwhHvAo8iFdX1KMa7OetdTCh
hdLfX3XG3FwrzJyBie4/Zmo2UUM94hPYWIoXm9BvELsu6SlmQt0Uz+vGrNYn7APGhaB2QbHlkOzy
h7RZzVAqajL8ZnVgMq3Tf3/PwCp8x2RwWyOnOguGSeTWVmfLSlQAtkptxU7uFU+1r4DCJf/BX5fZ
vgodNpEd0pB6qDT5lptf4/UYF407zzmOXcmy2edVVRZqdPxOCjB8Uy4/k6PGZeEUqz5rCimdFaOI
ZyhQd/5ieZsx2dErjgAETMuAOtpddCy9HejDQIOqyYIMMMMGe+Zrd9eK8NQEfjobSPKSRQ3hzQGx
jWTghr87yyl6J9J7d1fFHn4Owe66WEay50BxnW2TzPsJIYcF+t71hXIChD67MzJDDkqn2VWoHhoK
9JYFzzRUi08kCGB9PQtmNPDbJ/ByYTz150EqZstisR5OxAAzBfZhhtchsjQ3jQyLj3V1cwmAIrvE
g5aYZH8w8tlvINvlSlx2NmNSE5uK9TWNvOJ75hGhLicL5v3b46xbpRvL5AhKzsZZMoe1gUB8ep6X
Da+KLwggKNFnaLFlbaOjfSyXcdE1/xFSQySHLBYLlfIZLlhbaxtS2Z7M+eucwAMGEMMoCsaG4B/C
rcAtswgwEiDXnW8E4OZI90JmXLGuS/cLCaTPT1l9ZxbPOFNspV8SwaoxaqIqh4saDTXKzLJO6T6S
ko9P6flpDPWpwEMBWytLIdvKHdjK8ivsbz3+O2upMI8G8qUNGggZOgevsUHHdj5c7BxF+/Kt7KXI
hN4ybcmFvGmCX28VdyTd32glWmAJEwilwO7/quL+XSLlfcoDkI2HaNQ8mNkPOr8BgDjtU0oNUDFZ
TGuTs9Sk9u9mcDj+HGjhO5qFEARGPO0GDR01o26u2YSJuSBDb/ECcGooHSkKscgGf8hqU/2zDd24
uIxtCYqcb4wpvAOVF5AL029/c17bGxoKNKXCDBfu2Zb2jASRqvlCHYXiFrl5+PCtE2D7vnF7XROV
w+fE07dbt5RHjvEYfLbCWLBgE9+JBhlpgWw5ACXZ/KBJK4QIqyhHbF0gzEvBpOvPM+vqa/Ej9l45
b42Jzv/vyLUxm7CdUeM+gJkboOL2b5q8+PhkFhS4JxR42fJIk4l+yFkdwDKuTzX56ShP+Bshai6P
aejK0MaPHhGGxm4NJ939imkqSfY/IbxEn+TipiD6Sm+bmI9hAAb+pPaU1HvchyvtDuuiNawRxpb7
Xq7HU+Y7K1mWWkgGifwS2Qs+wAK4tI35EqGHyDwSYi2RfH8rpvb8e1LyPtn/+bO5DYcdvFoidwjP
OthjD65Xjf2aHTNOqOZyE1Sfwu9zPFJ/3Hke8DpymnKOB4ztXyJ3xw4lYk4USrkZ+g4e+TAJVNgL
Td3Ier24Qv/iXw3iCfPZJ88J4dEvZ4z/MZ5TGz+4vTXsN7NSTho3Ee3zSZEHJvsY026Urovn3cp0
xThjzcIHU5UWQQkipMIBB52XBFHdO5atk2XFmdJAuVWIyRKx2xJyx3y0NJvAMrfTD8Q0k+W87S6g
qqaH0xzbp4F3ypWDdKsJMZPMyq1IZaEHcklBEaB4/T6ff8pTsYzFcOZTW5DjQ51/6CJwTsUzBOFn
MXYyaa9wQCA6Q7eSbEvjK2oQx+PWQJiEoCuS6StA4dNyqvIHYDoW0QZvCBTSGr7jKp7ivMv/mAMF
CD2mD8eWv92zxRy2XozJKw1mhNTEFr7zhxrMUpwIjF+wrgjKX1tMRgYJEKxCgOsIoxwZF6nYPD9K
m6gBA60Vn0Ge9lp3fYDxIRVqUNNYiqSISpeqRigUVY7mqcuRIwwjZWhwm7XEfJ4wySYHmapTYHqE
DfC2UjdVHKy/K7HcH+q+ljDhllerdPYVV9CCTtSCQ69tb8k75r4+s9g6V5eWiC0rHPxMSYeDI7Qb
KEizVAroAoHkM/M6wQPuRTGufCWOHpiD6913rDIwkYOcpn8t0P1+HcEKRyJk19aLYnXdAHh6Rdpu
fdZzMBgxnpeB11TWT+Axw4wetwlCOMsvbYh/jNtSNVBmVjF+6e15uB9fesM+vMkWL951mvezFk+H
yNyzjPUJYf9pbB6r5d0a3gUwOp9r1V6zmBcAPlnvy+QnCCjQ7UMmSW5Il9T8CmmO8yrWbXfQGmnL
/WGJG9Zeny//Jj4HCrsrk/bLeraTSx/m92tReEvvE+DawXdloJcRa6iItSwgyfzmydK14aaWeo6c
VVmoxgkb/D/I5NgtN4YU/lLr+gSQeqm2KVuIrrfkCJycnEdvG2tHJ1WeC/Zy+3kVk99dyFTAj9Q3
wi9ZMa2nFvepKj+k6Dpc7XWCGqSYs3VH+qAjku+y6YprWTdjgEBbwhitTdAcKACRaXGB22ZuvWFw
mCsPv8WImlNXeZln2q/Cawg49s8ZG35PNOSAQIWSfkK5FpwBUb4Yv0Bovnc1Tyn0pEL1UNlY1QFg
HnGpXBfYLvWfrNihDY8f4cjrAfqDFBGry3zohwQoaEnsMVBaf/R9pHJ2W8aROajmGfW6lICy1XrB
c2Lhjdi7KeqeT0tEgvbeWeeeXlS8RzmFmVZUNioG8WrsSjEcb8RzhbKFv5NqhL44OtsGFWx4arP7
Pl154PS2V0+eFCQT1pTGicrrBtC5KrGhL2UaT+VZ6EyMlUZVKTOWLYSkARJ/kMYUn5B0PjxCvvnS
j47d/K3804oEPNnlzSExxtC8oK1PX6urHHlG6XBGAtu3lZtxEpdvjGgMf5TnyIcNl1dihiBx892c
LxExRm07L79DzFV/uZmZJsbriQeAEyB3WR/YjfItqCXb9PTrRFLnGsMsiiDaYQNuQRep/dAmfRsF
D5JLeX+u8Hp7vVGQJvDU+zf3YmMHUWVolcnsLBD+aPlTeQNs1B53YsCT18DkrgNkPe6fe0olkcUw
IpHhey9HF1HRUgJz06gEgdutg9I4duzmro+8HGMTx7yEcIKaaMGJu+lGjQpFfWsKomVTufMta3qP
hbYoJlz42Jv94r3vcJRhC7kK8Pv/tH928ooMCfEPIGCmstQPOJsPw6TuGcRLi+BvneTm764dvgoH
lFleA0BZbAZVsCOX2XfgehPKYiUVLs8/bUOeoty7ObFZzPueqs50Hzw5LNkvfaXwtnfvm3TsPGyJ
cQt34lj+ZKMSQ5+eMa5/R8bZwqVLx3IVH+Ou4Cj+CoDT7Y0FpuLVQRujVDqm6wPrcLbNRvthvzFQ
zswzATUuUuQUnjYdsAlG18+rWsxc1umAyP1JCs5FRo66jdwdVslfDk+bUF6SzJv8gcstF7wjo4/9
pB3q7I5Y1YT/xxwubfhi3Nq/DsrMobXXVdQM/eHjiOJStFVI4ZZ6PawNCROeCSWczfYeLkGZUihw
UrIVEfkR+4hW3fELPuA+EyxrVfDsNO0TAw+ezuEsg2Ya5uUM48bIlrd5kDOl75n+FrD564hy7mwU
/a7Buc65ZanRgTmKUwfc8Sp6+V4KCKyEANYyBsYP9Xrp+Z9qjT+Gtr2PUOQH3HLZr0DpG0fCSc85
1PeEKQ74evqDbXWnR2QTuWEmQlsYgb2qJFxoMyTB5DHnwvs//z0+ijfXTpBZdRBJJMV8j2ujBM0t
R+HYnJTICUX3BsWtHX2PR4nUZdYLob+ZfXEbcajVUPbtFOZgskdpiwULcxxCgUItw1dhzfvrvudV
ClzHZvATDf9TnJC/EEV5YvqpLLG7uvQQRDLQlyjtphcCKi0l098Fon5GWOgkjKtpv3s3/+TUl5ou
oN0KNwZJfZ88V7Ce2RW4AUPO7sn4vBbmDoVD0ccGDrcY87pCBhfOmJ2aCCDD7YZrAyzMSDlDIN2C
WLdYXcVDEQccFXJrEph66WCfMyUgaYXT0GPk67+ijQ8/KofVh+FLsqw6NMaalix3TwVJ8LeNLn78
HT8Zpxo4i8a9r1ciTamMU4NrgZbyUZuG2NKuRzNNScXi/3u4CdoR6Wc6d5sNi6plnbmTOeWIz5z+
6Ml6+4aUgbmdlb45Gtp9WUAGecYnVyyPcLGfVijcm3+/y79JUXp+i9rL45jgF1fzZwtvjvUEhiKX
7XSF15uppHUvMWHx4ho5CNUa7UHRvcjX9rH40+M1Qxm5SwvoL7SdVbL3L4eTYJdIu46A1RlOBxBV
p/T/CKlb8rCBXPbGIfjg3I2bszdZie1nuYFcJzukywb9liXz0mcBhUzqW4i5Gh2wqst1+Av4v9qz
z93g/+c5IWK4jORSIgq0NkzbuxblDgkx+xGR6RGiMR8VqSf/hApVjfhDquFB37B19hcFfFaelFIc
8/cw9AgCci1+zPxIbQHJY1G/yqi5FDS1+c+4ixSUri94/Yi3mO2UwgRS67QoBNSOWuGv9NvLI6oH
RmqRJOBMesowkn1trgIr6NI8IypLHsZylt/3ufGxk86OEGu1L3fdqyuvcZs7tJkb+nbnG5nHBbOE
WDquA2WTNLpNLXGd/icbT0WDzvTS3Sd9Llf8CtBJ9UgQVZCIfMMZgOmwynw8OLJa3aVx3TrZXiUz
NLrPWoxWyGeN7xhMDq7ram/mFDIimIpyQomLq289MK1JAEyTfZfa1S4BTDtRPEis//ZScAKGKO6e
5Wv1qbuYzP8Dk6esAFCZvRtdY0VK/YEMS1c5bC8y4IEah7s1fj/yHTo81L32JdEB59CypiGn+DpG
9vUaq5Uza+DoIHBZQNA1HQd60cSmru4PpGL8gBakRXEq3iVBXB0bwCBv/MehuuKPx1AGikYmfY0t
iWd6j7mK/Cbh+DwnUITs82paMtgS6zUGa/4L24t5NpfOYBUbbU2ZSUpRyhhtlpLJxRMXHkR59LId
b+RpQEwmuzQ5I6RaM90z61BNkDDb1b2crg4VuA2ig+6UFkfvULBKXxSTjoHAJFHloRAA04nbyMW9
+/s4gAQOLPMfWAocv4LSmqXfzTiJhUn/sSvN3pNmgOyq0ZFF4ne9xo69r7ihVXLAOAf9M22k0Vui
siI8SZ4hN0EnOfPyQQIRREHbI+ol7yY70o841IIgR5hUdtEw9uIpT4oiwzHNjRHx2iIbiM6IUORE
nkSl4eFrO01ETf9ccAD/I0bTufwh+gnzJcsg2cQj9SwQlGGTp9oX2a+fhZcMEC3oaNj0oWsjyo6P
gM1ANMx9V4zOTrtj9Rp+bGYTq34PBov6FXiVynS9LY7keyTwJmc2I4IMiQEU++XHxz8uJrNYHJnT
jxgLiMK4hgCZzE5xKCtxOX9IFWXDiyDGjk0ieMk5bR1Eodrk3yzeF0rA+A0PqhIZSkSgUH1QWmvG
fwzxj95IAvFsXGU3tUSEzSHBiVyo/Egf7MXoJA2/twDCqRpIr45s7sOBc0d3d/wd83jx0lAnKRiB
htAPkZ5jKnNCEKHOc5C4WsVe2rukEtN0vMo7jdw6EIRsqO+z0FLb3sfpiOJJsGJWwuYiEgVhGEHK
x36IdILbdL4WrxAnCCfHHjeKxGJ2ZuYl5cprNoc0zmfuW0QDW3q0j3mylFlS+xjXUY6lcvNkTWH/
4a/1rKzF2vZnA5X7QcDQANToZFrCMMPXBfdjhUhDtMvEYHSo0wstZJ+qvGoa6AoEO/WBegTo8hUS
dbFUoMLWkvNMMgznM74GkwqJ1vqY1oopk15BZ8aahWaovG4W7vPlJmoKPGzl3zdn0WrbvO6xqkdB
gZbS+z1JokxCMWDjjEHYj3c9EqnMJvrbX1pFRSTcRtiBxhFnlimDatUpTNXkxC0slRMMgfP+kr2Q
MZu/T58oIEBPIQ+9qVbARxowIyPxyGuDaugV70j6kvcfSs2cyavMzbmIKOw0R2Se/CNIJcovoIY+
TJz+OGasebc+Vxm42xnNHwCMpDH9PAXabXq+Xt3KauDuWYYe3aA71Yp74eoQw3l5ezYU5u5mX/Ue
wkWAUFvOK3ffMeTBDJhFmd2qT4b/dASrLu54wyHIRMxQX9SCa8zXDevxY/WQgVzD3/iBy5i79AIr
C6Gk5546lfzAvqhsWpMD0Jt4oEAQJGSpdvdEmcquQcL9ZyEdn3Ih75dbHSTyA7Nq9u4MeOsGw+CT
rWWcHAkAVsC+fv6/r57HvojqQsRxQS5Bjmv+gI+cFKN8PRTdHZF+EIvjPfALdGGaRPLZWrIs8AUJ
BA4vKn5GT5dYs7GeCsCOcMe8rOP7+K3vl5X0rOHyJ4OSQddkixiZ5oLnrZnrXE6LStcSW3oT9ELc
K6J/1Lrnzdrw9Zdh9/Ix0jPD32R/Rxj8sb9bhEmuJGKj3Z8d0QKsclzDq3dlRJPgMYbLKk1Ez/gn
pGQvx3tgsLmqOvm3AmAXHSuWsGQaY/VUhqZUvnLtiMWiWMV4u8VEkxhbIig7DORkiaKMnAntfQXs
fiXxsF7LWQxh4Dr0Ok1o8sTJ+pQFFG85Bsd8hTs4W+KBcmk39//d6J3hyw93g1ZzsSuIC/DiI0kT
0SdIBhxjE1cbsYzUMTa7ejL21nNhPrlaXZgr9cCVztBmDoDUiaPx3CfNFN+KxiDD3ROFsXKb5dJZ
26nJqkSsdC33/Po9t56JdJMia7A1+Fhyv9cLBfoHtYY/Aax0jotAN59165rqysEwwOl65FpVVG/8
E+narK//AtdcMT3eio+Uk6elePS10YPkL/xy+8mGU0RX32OZa5xS1Ob4XUE63oibtAfu5zbGcLvl
IKYPcGJLfXCX634HUO+iyprXeQ0bGtrh5WJLcOhJPApcyaW70paRjOSRJhDWn6N5PDOZQHmS3KKG
nt4b6WegyEPjV6hedioelyq/z6QlyUPrYfl8cdhFxMwrmooMAGAFoa36XARUuhFLLq0F8Crk/s/v
+6mbsxT/jk4NdoqDNYhDI3rxOduf/tpFR7FSkC17WuA35xebmcAUR1pBteAq6cbcOwShkjbAnazo
Yw0H3YA5PZ9yugY8XghsRQbav3E4vp8wQ28bgpa/qAbLmHeZimd4cw0Smb9tBfQqmM0E8x7YxHbl
s64f5Aweu4gZja2Fys1SspfpeuyvST53w9Ym2KtXzIF2OUevdhr912LWijTph4mbTIhGnE84Xwv6
gag0CB6P8/+8qBepBf9XvJ2oP2yWElBZrynjDiwgjZ1bD5OI3FbC24/1FZNZ3EfDlbTlE9+OBDuM
d6MjA7JEY+EMiPCKDMVTy09SzXM9Z8kRgWPrJw6QI25TVLX02AcioQIKVcuD3z6nyYUCqHG4leod
X/unN/KAUym5NKawcu99lTAD6SkaD3F2/V5D0osV+HeYDiTTLaSzXTSMDRisDyg9NubrpjAcE0CM
qGjeG8017srGISo4dLBAD8lOXoidrbgKrSb1oyRaZcBFerEsdQLMV+sZKbnK9B8Qy5lXzKAjXHiP
X+IrTMcYljVEaPUKDUAqZRcftzj5lY1zEQ1HvtnkG9VG1t4HGpS7jHr0hqxjIQB3zc3j+2oJ0Eqg
oqSgOO+RzPEAXxZq9/xf84SR7b7oF2KThRx5VSVjJV6TfYwHxwgkShFDYLk9iCtIW/QeHq497fta
vlw8vU+nU2wEwTQlX9cZVJl4ogTuUSHQVz9IP+8ISWV/hWfH1a0LnVxuODDs+UoJyWaRs+D7LnbG
IOpGP6BSxsYBYOTD+7PV3o7ev8K9wKm4AGiommcxtQzkl32SbfMNK47riKx+lWCd0u6IggETnr4F
ctqNI86Qp1ngM3NhhEnw5nMgE3CpGyjfa4madpyh9EQFZr5mTZDuA604N7d8lD22F4qgUEy2J+by
+LD4uIyd+FTKweGUw5eUILgUPSHelxovmSiG18VcfnTklAHHWGnaEywDXtyMhtM2U9ubqso0ZFb3
ZRNHeHUyzpyfTZatfdXUZCNqidCDuGUDURW7yL2hMox/m4PgmbkIKRyIUVrfyEtWceG/2BuQQsAE
OeK9crZvyw73SqcTCxRDKohuq3Y3OLYeq1APvPbuqKKtKCkawdy5nbEt/sQFItSeUVxr0hyO298Z
gMZDk5LHozN9yGjpLzDGhhrP1iiIXcFsSahv/5Gz/MTybPmswKl9Qpojsl3a5248Uwr3MZ21TARU
FaZI1Nr8h28EEy/fAbC+R1GcqJDnPxQ6HbvF5e3JmqH8I7XMxaQYhyqGTOoMVahi+tYIrDUA0TUA
jc+7BWObJu4e9smVy/HOEf85R3saXSlQ1cO4lumSi1AB9dsGWsz3xwjGYeOG5TDgOL+onjrLCAbh
xSF2xLqIQnU/pvq299woeMKzK1xAiL0XEqAmIb7Vewhkba/O2PWws3XSZ71o30pw4Z/+5R7Wfvei
wIFx0UvZeiRgl5y0sXluDIyzU2U3Eq3RdKVHVmBkWu7Eyf2OTmsFdA2+dA5aWpUnP6Wzyz+PW1GO
5TEbGTKWkHsk448LZRbFqUXKM/AoAJ91RRPVfGFXEb5BnUEXDwWA/JpX7lJ6UA4S8gkuTTcnP7y+
wC3zbwDpxk2LXWs+aIGDdVuAoTEvyxG3NPoXcrgf1ZIsbN+MM33YSfw+sz3Mtw7alkYJHhSfslRN
MWZk/pG9DRiRm9H23wfFKeHGZ8vuEa29vUPymDHWFCDsLI05gc2gDnUtmwd7qb2I2QjLgU9+JBQd
vao2gi8z0hmAmr8UxL+c/hEH5wJMFE/sLUoFiDVuf9fzxCvmd9F+gVvvYnU4IHwL9snZL0OJN39b
E87RRqpM4iYfe6in0FP8fHZitQpzn/TR1qBPksIcqaCY8U164N+n8hMMszd0vMyGXw5q8PG2hBId
RGIcSh74PjgeUqCpy+nuuu8LyHxin/Hck+DZuvD1IqiTHspLbH53MliwduM6JfSjdOtKlhh4wh/H
VskanwlQ0vIJCib+NKOuuOgaueT4epU0zSnhGPH8o+TwPOAgers74yKT0T5H0mODz9VvtujJwVSS
2DdsQZB34zJsNgJOjWxbw3uawJXbzQm2kboCkBw4UugOl92K5kSL+vW0WALzMepcP6f8zeuxhcGI
5wXABM3dEqelWL71fgBZsa0YlH6USEkoRq3UDc/jdAHZ+85LEtUV8YRRR+TLx1zZvFm2813pVayM
Afk0AFqQrwI+NwyYRPidv8HCAJUgorFEjNASfnfGa04bOwzAv8k5+0ehYfcWx96feY6Z9qHEnIpx
bN3vHdkpGfGYYbImgk6wybHYPU5buiHKKMtiLAfNOzQefR+0JgeoziFvGdTLipZFuXTkyPkR/dYi
NeogVu7XUSDpDH5p0D+RbW2EMOtfbcNwt+PFxdDeT0Ux8PIu0odWcdaiCXMQZo19rH5I5+SH0GJn
Ausj3U0HTO9jD0OZfvhGHcvgQCNMOsrHyNPIrPW7ueLLyEHRMTMZ1sgZ6hRymoLBSv0T2HZBEFE1
2dMZAZXEF80mb/VUXx4dhupodopPr8Wi9oKr0PY8V3E7pLewbbb/7EVc2pccFWr/TIQFrJ9JZhXW
oEN512sZIIL9UIdB3CKG1U8tQA0vg04+YVBms0n5ReVNa5ViU0IBU5YolgZyDfFQ5XBV1VuZDxVE
SAZSOPYMD7LpEMblDYroUB5xRU6LKmq6TC5E0SlZZv+duboiLYxLSwM8aWiw9HCP/nFu+WnEvKfi
qDmuiNAGjYtZdD+zjOZLMp9PuXMhpEYZMuj3DDZtCxRK1jLPfvlxmyKW7kF2/saFzxQhXfHP0Naj
CXvyRwrWYA4HIDPbnEL3jt+61qP+GrmjtzGxpzl2fWceVlONawYWf3xc2GlPTAZ8AnBtGpnvoOk4
+4jiFbrNfeQtcV4PKHww+KvpsQWHQPA+bX/azOaO4UQoEMQgqFqveMK5tRI4SPEnf7Fk9Y9Pcm9u
NHPGhaYVYv2ZJtGIZqldbrX1CIKrk8WxCOF/aAT1XgIZlZrr047Qc9IVV3KZBo2etOds8+F0zJLG
8o09/eH3E+XI22UbW7xS3UlGSqm4YeleybWsrZwTznTPgo3pbYSwD+mNlM3PhccW1B9yksNNguyu
tYA2OCEDb+3Ut/LzHuWz8akISwbS0q/it5ANkmRNxbJxTTwm5ZeSK9TlJqXe2EBD+tUOQcONLwtG
tFcIe5r6SbMHSN0CZQtO66hMEIzaMU7l+mdvOrL4qKldnNlMhi2sHbEn63uXTe/CDP2zGt+rYEsr
varXo1C88Mh+b0OcEGtycXYTMZsKZsQdFeeg6v1j7bzCFT552DyCKwAaK/MK0lSA0gmRIbTKWxjb
hRg05/sTguYOeODyW30yGNYM+iP8kKAScVfqtmmECrykLHiRscVMklFN1YX1fXCWqWZ4XMFrsXp+
RD+tOoVYNnIJX94sauvfW/eAuqZYPPShfaXq0iBTd1tk8IfA4bneFbtq597dXnGYVCTiufYM2zV3
fixderfVXEhf5Wog/4NZuRjaUTqmcgqWNdD23o+iLhFOSqeZ4VRLhItlRG5+ZnCtQkg2hmkvBZjt
sGv+pVUVZGQoWw42FU+SLL/nOhJmpCYAx5UUriQ+cT/OV//NXXa0ckD1SusE48+FYkzVQJVF9A0t
HP/qNaffbzKnSu0DLE2rQ1iKAmG1Q/McCiZXfGCX1iigP3UnXCcBaZS8g9NORnuhqmAmgCidHLkQ
M+5+FcKDSy0REmZcExDnBJKxsYRhZ++7Unj4U84Ylb43+RoG3n2gfzwtdpWAs2hk6WinMkJdR26j
NPEkIOHPUY6xaGFHHYYwC1ZOPdrC5Kx98Uj+eM1kyvjDPa0rx1nDp1Nu6aA15SZvt6aWbo0gNu2H
aBYwv2+GuAitoWWB8sMwHJ5YKFh27yt8lrx/qqI/iRyIQXoOi8y2b9AucXisRI+S7wpZKf3e+nkJ
meaG2RYVVymgLMT9rPDUGqF1NIhQG9jfVzOaaolrswb3VSb0Tct/V/i87+dYhje/9KhNUnU8x+IF
gPRgEiJc+mXYZq/4l3R4Je0NxEi3HeldnE6U/hy6QdX97rN7RHxW9S0HYJwe89JYbj/TFgbCJD3U
RZXuJ7aoGYXRSApD58/AkaFPAXbfmAFugGFMdK78SyupvCKeZfbCcBlw6vw6B6/BJXUiPRkxQNH4
NiAfJfB04E89EWRa17gSD3Gt2H/B6uHB/u5X3KWa6kcWToTZTJLf4xGh07Bqv3ju0j3opYHKjUh/
S1J+2auj/JytRd1Z++jNYqe7oy56VwnqYmkFEv2KpCwxU02/FcZ8i5HYcl90AbcqO5GzVMTzZ2G/
+OsxXIHHU45zr+IVASjlyqlHZxE3o86uURSiu0Pdv55kK8F4daEiAzYlQ36siyPJ6zCPVoIVKSp6
WOZdNo1up+60UcBffB4w8UsrpQoU7c0aibE2pOCvO0+0f04Z6dZmPQO1gla0DZicxCBNmSUlM/zI
qQj6M65ZTzlrMHwdJPD8BgmxfdQ+ORD25TIs4oBCDRUowFXVBuNsN5mlj0uWPaSFRDP8AL/ZuHP5
aeSLI+1yAuky7Jjv+TJiRALhqYCqoP0KTnHS90zTPfiZzwpP9SCyt1ir0JJWMaK6s/ydZHXwIiEW
ZLVJ9fscCqBFmMQ3jbdj65k1yGV3ROJfwjOjoXBeA+S6R6PT3TUcankszZx8x0ispIeBkm8FuxOT
KzPLzscVqmI1vJt20DM7h9YqfIHqXXsu5ffwuvIM4Q6BNTNenYUnZoXldwZMLBWWxCRzYhs8rFBU
Csux62nRuboM2eYDIGBSgI+tgiraN38Syblf1++5yrE6CSHFxqEgq/vLT+BGXTO9Vs+W7L2wLbDn
cLL6Ctz4wT51YOIHTUAbfl+37HWNS5GxfDZy5PhSouiOlqxcJNibDCchU1ygd3mAW4bj3xqYMUJr
OEaQj3FqOTVxWFRaY46Bc9qC905uXIUBX1cP9cxoS5b4ANuB9JmA6lNwPSyfmeFWALIr3J2ekwCl
4lafjy+6Yve7SlAHGOwjb1ESrklbmX/sDSO/CQ+cfKJ010IT3+Hd9T39TiLpC3rGeFcaiQbYDdbQ
4VVqT0hMzz6pu65SU1AcD8oXnTLybDYNlnGdQYG0eJNIWxgaMlP9wUxAAsg9+s7PTe5fXg+bGYwN
vX5LyaVWEpgUvOpyQFCvQu+34TTq7dNGuZrs8FSK3AwaJn1mkOQ1m+F5/SuimazSqFQ7S6vnx59s
q27ZL5o1kwIXHMjb0nk3XmHwmWxbOXU3LvevEZrjZxFPw2BkFlzQZHG8Uxbj+6G+j3o0C5koms8p
57e3/pCA+TmY0HtTJaTHof2MoK+h01kTYRUrPyBBXd27qlu1OU8x2FlOIAcF05Ws/CkjgTUcw3G5
g40W4YfEarhRBR+qfO/hyJ0w8oad6+Bmi5U+Q42MWHEDUx7IPMzNPpr1X3sc78kGAmoPOk/pf6Pl
FGchdJlQ2IhEUiuualZ1Jc7vCxD9g2ZU7OqxaVIXySlbVHdPYSIZl3C493gO7IF3TjiZgqX7fKJ4
qKKZX1BE/kiROdL33goR/o6bHRYQZ0YZifp81i+Ya1sm3bkhVQTF1grmLkyCbowOyrdMWDRFsZwt
cPKNhFMLKL6KvZJyCn3bEHO+FAuW3LoYcpGAovy4CNAue4m3ggmPjE1MhT8qBfhFtbGCHmvuwQyn
m3m3od+3FwvJTmX0ULuBH3bR0txL7bRcBaMLt5tD+X+znM2wpiu7Kf7G36QbI2dSVjMq+DGsZ24j
hS6Iha23oWGuztmbcIgpaiQFYptrzl43pG0ImXE22R+UurXnp2Awl4LSt2r5eH3CnIXdOoPZ1ER9
Cux0/YFwLzJJ0pkZqsSgmi+dtmHp0M4G2em6OHYtUQyXOQLDI9tCgVZ3Omtbg1dO1w6/7ecqD+gR
7iRfhtH7WQcpHm05bXDK/8GGy3pnzo2EFlX4mbK/VmYtTESFn5PiU9aBjS+Vg/miuWvuNb1nt6ri
QSQabpI0/EWSsb5yb2BgyMI+NF7wEVZ4qxfe7dDSQ1UtPio/SQcMTk0EyMcdZy3e5eCqyq5m6G3l
FBKzsP+GWNGWYDv9tzZ8hAUDVfR4cGs82mHVjXLiHy5NeVJITO7TWJbLpjKM6YuKcZeOdyuUBx89
Gcs3/5+UMVHX/rPAXNU5C3OrVmKCN3h4MrI2YJsou0KGr8A/KQdt2ygCKaBlT8rUMRpHHbDNe6x1
Gjr8mBU+j4Rqwo62Qfvtb7fKevKgXEcV5IrU0AOx09KKNNx5+bXnmosBGWXh5yY6f7CLNn96tkYR
SOWsVhwfg73EduansARZqCJ3gcLtIi2zEQhqE+6UR4FohqnDENpRhO1h/ht92A405tdlqCpR7XBO
capca53W7kurPkP/UgMSjTbippfhkesYKEscGAFiRWtJf1CFzTlfYenPDUCodN5G/1GdcOffMrFz
VqcgMbUPL4KqNfx1GGgYD5ac4Il7f/mwJRmUiYgGElNqITussWBxNfB7CCOSflUGgFArM/6hPpQD
pj2VDsJBgVIUDIekmsjc0BEV/PWF3IrhTlgwaHzg5xD0fuQbPAz3XDgH4oQ+SCszMgg9hE6yibN5
KMUx9jpYCNC+AGAOpKkoAXeba0eiwfyQH+gGxV+NdjxswIbBpPfPce7Os7XfziXgcq6xZNv/wolp
51UFb6jCI7TTnD0JYyFbBtHmMbmu8zt4+Y0UC7Dmr2SusaiMgP5apeYt3XkP/AEzw9YAg4DV7iic
LflRFppMnQorsEppixO7Vsk/FDIYrj/PVqTnsUZ1LBaWVx4Eg6idcWLEkdygwJNuZk+5RYvDycUb
lunwlEu/8dWca9xL1+TgHU7Lo55hxdN6vVPMSROji/XyQrCMsqzZOFKs3lydwBPwec/nQ8+QlcN9
K9EChs+25ghPDDSJF3HxlJsft10KhX+3QrG+/y4UhtUa+NbOby6PR2XPH2QW4Zcnyo3k0SxFzAry
gt4r+yQwDYufZpcTp1LDnTBBLmLCKlHWOk21dKtr3Vq3T3b0zofcwVvk1EdIIfnwKbmwv8qVV1k9
lVmcdRQWTD2+tKMIwyZPcE2R5jXWjjS3vVczSvCu+lP1RdQ1W8XMC26Fvk8zGOIYZ8WfDOqLopf3
HQwnKEHumBP30/E1/OGiLr5A9uGIwuE69yPM8kc4A03w/lM5AJ3Q2DB6MdJ0+IIvPeQPDB/pKSID
a/zqs4ttAomrKRG9DcHifV2PdfW9sjd+9Rn/SbdpJ+Jmf3gou4Aph+qyawBiynmlnOGM0gEcE0ZH
5ZoUmcHQ2EFGEVlDle06wGMf/r33IWC6J44R8nUN7POWB6Jbps5Py3rZLkiNP6fZ1+KZyaLkPVxk
fqxZl8Z7SXKLHZtvfhLVT9LuX9u7EoTje9cn8AqypqMnMAhJDPIm6jcSCUZpJIvSA4qilVVt9XzG
mUNPt804+mV8JaId2iMxRb7OTqsBzgX3qlQbXl6gfxCerkyTo7OD8AbcthjSEiwRr8I6wOm7XtOO
UdnrQK5xIw3FaXx8RNgFL2Kk9vLdt4xGYkMO3f3SY7lI6Mm0fFwImKdQ6aqT/8d7vKmVLfHnScYP
RqrURXq/bg5d05IrcKdJRDxhGkRZaF1V1jKNMlKWd0DorLKKFcPSrOTGwJrFv0QfiqpU4aiF3qT5
PiCVatZpAKS7Xa8nXmi9k3c38y6YzWIls3wYfHxsDVMZrODcVy+kqG7Igfi61D4BV+Bjhs9UUbDr
lRSFXGWBqmJg41dlW/ArXmlboRkHKUC5z0pknRgyUJSMJL91/v63XldbibezpLb7J1vxWpXXcv2g
hANppDM3S/K2bVtcevOj0YjbYIgFTv4cvBZ3/v3WKpb7GiiS4h1jdb5yj5mO7ouv0Egqlxk+U65A
1Wofmheauzby3dZpjE8S8dDXq0Jhgol3uaHhJXvTBVvWooIBffMjKu4AT103ndwCl5IoTlfvV4PA
kWSraY2eZ2KV7Jy10l7BA9EvcZ3y683V56vMh5IaqrXMHrtu0ejdIIyieWQg+7zOy/gWhBWGvBGy
2ldDGgWvKF4hNWfwU6WyQyPg9Wv4X4wSOuTlCDZOCodrlnFxh73yQ4V6NF2jAQUqVUfsdArLQ6ce
ob83jFF3gDcBm88TustmFlwZ4A1jmS3Zd+KWkjtcTbkq6edVfPxAT/I6nOIqr1QhBxeQeV8xJfqV
+PEvYvFbRC6pht7R20aKtOEfcLkArTyukya2YTnzjhnhYMyAv1z5OFYOYmcZTCrvLo53e4INsRNy
VvPTEFmd9hmC1KbF08FryDqrGa/BG98J5iFTfYUZObKpiaFYVomp77DMxkwVzvg0EEzGp01yTBV/
Xr/LhoO+Gzf8Zg4nIK40q40h3zSWAcFQS1kb6ODwhwEMHuSapp56JG2ow7wc38bT+3ur6dZPJjtJ
qaTPyYBQ9X1G6sZ/iqFhVGvsW6qXmUySPyPXjWgD4S9sXnq63/9fQ4PlmhHFpPaf0yFpesP7f+qK
S3TuiTeqByu8FaquMLEZJEz/oh97LV8XMGUnJ0oWV5lf5f23houOveQMxwEWdUXEO9qK+B9DfB+V
Oc3ms81iqcVbDQxTD9Ezu7WHTVUxdPwViAEq+pSwc5mhbYIfW2kieYrOPRrckpveLgu64zC6kikY
IVPeSiTnzH4rtWHvraFCB+OTnogI2B17NWzXxNY30aCy0S0sxxUbgCb4OQhzzSAEwkdQZmgqd8E/
iQR/3Po2KQCsdU5cHmOJ1YKRW+h8eJU4M3BypvdRbzNcdR1PO3VdMQs3AiJm8BxKBINwPL5FxdPN
36LXScurXJrJ92ouFexVooO/6pJiMUa3TPXyG2yOFX8ycv1DqtUBI1Jsr2rS9zA6XkpnNaKKWmLW
J05F0N+9uRrA39UVyqpQ8WqbjJd6NstoS8rMzKJE9Rxpn/PmKCVmGp7CMVftEr9SvymwoeWyJLqT
vHva60ga7yTNG5oWG0n+LcbLJcaQUNtgSrMhdlTvb/avvIJgdLzTYyNBIs1qh54YJM7Cyf6QzA8G
LFdCZw==
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
