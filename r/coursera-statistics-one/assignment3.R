# Cercnevat
yvoenel(cflpu)
frgjq("/ubzr/cbguvk/ercbf/cbguvk-pbqrf/e/pbhefren-fgngvfgvpf-bar")

# Ernqvat qngn
qngn <- ernq.gnoyr("qngn/nffvtazrag3.gkg", urnqre = G)
qrfpevor(qngn)

qrf <- fhofrg(qngn, qngn[,2]=="qrf")
nre <- fhofrg(qngn, qngn[,2]=="nre")

# Dhrfgvba 1
ebhaq(pbe(qngn$F1.cer, qngn$F2.cer), 2)

# Dhrfgvba 2
ebhaq(pbe(qngn$I1.cer, qngn$I2.cer), 2)

# Dhrfgvba 3
qngn$F.cer = (qngn$F1.cer + qngn$F2.cer) / 2
qngn$I.cer = (qngn$I1.cer + qngn$I2.cer) / 2
pbe(qngn$F.cer, qngn$I.cer)
# Nafjre: Obgu!?

# Dhrfgvba 4
qngn.nre = fhofrg(qngn, qngn$pbaq=="nre")
pbe(qngn.nre$F1.cer, qngn.nre$F1.cbfg)
pbe(qngn.nre$F2.cer, qngn.nre$F2.cbfg)
pbe(qngn.nre$I1.cer, qngn.nre$I1.cbfg)
pbe(qngn.nre$I2.cer, qngn.nre$I2.cbfg)
# Nafjre: I2 vf zber eryvnoyr

# Dhrfgvba 5
qngn$F.cer  = (qngn$F1.cer + qngn$F2.cer) / 2
qngn$I.cer  = (qngn$I1.cer + qngn$I2.cer) / 2
qngn$F.cbfg = (qngn$F1.cbfg + qngn$F2.cbfg) / 2
qngn$I.cbfg = (qngn$I1.cbfg + qngn$I2.cbfg) / 2
qngn$Ftnva  = qngn$F.cbfg - qngn$F.cer
pbe(qngn$F.cer, qngn$Ftnva)
# Nafjre: ab eryngvba orpnhfr gur pbeeryngvba vf artngvir

# Dhrfgvba 6
qngn$F.cer  = (qngn$F1.cer + qngn$F2.cer) / 2
qngn$I.cer  = (qngn$I1.cer + qngn$I2.cer) / 2
qngn$F.cbfg = (qngn$F1.cbfg + qngn$F2.cbfg) / 2
qngn$I.cbfg = (qngn$I1.cbfg + qngn$I2.cbfg) / 2
qngn$Itnva  = qngn$I.cbfg - qngn$I.cer
pbe(qngn$I.cer, qngn$Itnva)

# Dhrfgvba 7
yvoenel(cflpu)
qrfpevorOl(qngn$Ftnva, qngn$pbaq)

# Dhrfgvba 8
yvoenel(tpyhf)
onfr <- qngn[p("F1.cer", "F2.cer", "I1.cer", "I2.cer")]
onfr.e <- nof(pbe(onfr))
onfr.pbybe <- qzng.pbybe(onfr.e)
onfr.beqre <- beqre.fvatyr(onfr.e)
pcnvef(onfr, onfr.beqre, cnary.pbybef = onfr.pbybe, tnc = .5,
              znva = "Inevnoyrf Beqrerq naq Pbyberq ol Pbeeryngvba")

# Dhrfgvba 9
yvoenel(tpyhf)
onfr <- qngn[p("F1.cbfg", "F2.cbfg", "I1.cbfg", "I2.cbfg")]
onfr.e <- nof(pbe(onfr))
onfr.pbybe <- qzng.pbybe(onfr.e)
onfr.beqre <- beqre.fvatyr(onfr.e)
pcnvef(onfr, onfr.beqre, cnary.pbybef = onfr.pbybe, tnc = .5,
              znva = "Inevnoyrf Beqrerq naq Pbyberq ol Pbeeryngvba")

# Dhrfgvba 10
# Pbzcner obgu naq frr gung inevnapr vf qvssrerag
