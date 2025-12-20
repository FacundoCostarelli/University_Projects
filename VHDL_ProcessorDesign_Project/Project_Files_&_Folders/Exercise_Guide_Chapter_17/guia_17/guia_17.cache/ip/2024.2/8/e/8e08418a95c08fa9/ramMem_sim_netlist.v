// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.2 (win64) Build 5239630 Fri Nov 08 22:35:27 MST 2024
// Date        : Thu Oct  9 15:43:19 2025
// Host        : DESKTOP-38PF9T6 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ ramMem_sim_netlist.v
// Design      : ramMem
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z010iclg400-1L
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "ramMem,blk_mem_gen_v8_4_9,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_9,Vivado 2024.2" *) 
(* NotValidForBitStream *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix
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
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_v8_4_9 U0
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
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 18672)
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
