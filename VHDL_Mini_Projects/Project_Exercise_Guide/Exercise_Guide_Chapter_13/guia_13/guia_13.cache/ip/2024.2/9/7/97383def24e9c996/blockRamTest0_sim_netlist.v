// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.2 (win64) Build 5239630 Fri Nov 08 22:35:27 MST 2024
// Date        : Wed Jul 23 15:12:33 2025
// Host        : DESKTOP-38PF9T6 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ blockRamTest0_sim_netlist.v
// Design      : blockRamTest0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z010clg400-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "blockRamTest0,blk_mem_gen_v8_4_9,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_9,Vivado 2024.2" *) 
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
  (* C_DEFAULT_DATA = "5555" *) 
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
  (* C_EST_POWER_SUMMARY = "Estimated Power for IP     :     1.51805 mW" *) 
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
  (* C_INIT_FILE = "blockRamTest0.mem" *) 
  (* C_INIT_FILE_NAME = "blockRamTest0.mif" *) 
  (* C_INTERFACE_TYPE = "0" *) 
  (* C_LOAD_INIT_FILE = "1" *) 
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
