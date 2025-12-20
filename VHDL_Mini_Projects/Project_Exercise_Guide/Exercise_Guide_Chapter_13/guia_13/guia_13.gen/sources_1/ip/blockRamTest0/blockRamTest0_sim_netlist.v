// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.2 (win64) Build 5239630 Fri Nov 08 22:35:27 MST 2024
// Date        : Wed Jul 23 15:12:35 2025
// Host        : DESKTOP-38PF9T6 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim
//               c:/Users/Facun/Desktop/TD1_TPS_Locales/Exercise_Guide_Chapter_13/guia_13/guia_13.gen/sources_1/ip/blockRamTest0/blockRamTest0_sim_netlist.v
// Design      : blockRamTest0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z010clg400-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "blockRamTest0,blk_mem_gen_v8_4_9,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_9,Vivado 2024.2" *) 
(* NotValidForBitStream *)
module blockRamTest0
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
  blockRamTest0_blk_mem_gen_v8_4_9 U0
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
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 18656)
`pragma protect data_block
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
JljaEwucKm/XMQPkMi0Qa8Q=
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
