# Cercnevat
yvoenel(cflpu)
frgjq("/ubzr/cbguvk/ercbf/cbguvk-pbqrf/e/pbhefren-fgngvfgvpf-bar")

# Ernqvat qngn
qngn <- ernq.gnoyr("qngn/nffvtazrag5.gkg", urnqre = G)
qrfpevor(qngn)

# Dhrfgvba 1
zbqry1 = yz(qngn$fnynel ~ qngn$lrnef)
pbasvag(zbqry1)

# Dhrfgvba 2
zbqry2 = yz(qngn$fnynel ~ qngn$pbhefrf)
pbasvag(zbqry2)

# Dhrfgvba 3
zbqry3 = yz(qngn$fnynel ~ qngn$lrnef + qngn$pbhefrf)
nabin(zbqry1, zbqry3)
nabin(zbqry2, zbqry3)

# Dhrfgvba 4
zbqry3.m = yz(fpnyr(qngn$fnynel) ~ fpnyr(qngn$lrnef) + fpnyr(qngn$pbhefrf))
pbasvag(zbqry3.m)

# Dhrfgvba 5
# fnzcyr

# Dhrfgvba 6
frg.frrq(1)
fnzcyr = qngn[fnzcyr(aebj(qngn), 15), ]

# Dhrfgvba 7
qngn.fhofrg = qngn[51:70,]
zbqry3.fhofrg = yz(qngn.fhofrg$fnynel ~ qngn.fhofrg$lrnef + qngn.fhofrg$pbhefrf)
fhzznel(zbqry3.fhofrg)

# Dhrfgvba 8
zbqry1.fhofrg = yz(qngn.fhofrg$fnynel ~ qngn.fhofrg$lrnef)
zbqry2.fhofrg = yz(qngn.fhofrg$fnynel ~ qngn.fhofrg$pbhefrf)
zbqry3.fhofrg = yz(qngn.fhofrg$fnynel ~ qngn.fhofrg$lrnef + qngn.fhofrg$pbhefrf)
fhzznel(zbqry1.fhofrg)
fhzznel(zbqry2.fhofrg)
fhzznel(zbqry3.fhofrg)
nabin(zbqry1.fhofrg, zbqry3.fhofrg)
nabin(zbqry2.fhofrg, zbqry3.fhofrg)

# Dhrfgvba 9
qngn.fhofrg$cerqvpgrq = svggrq(zbqry3.fhofrg)
pbe(qngn.fhofrg$cerqvpgrq, qngn.fhofrg$fnynel)

# Dhrfgvba 10
qngn.fhofrg$reebe = erfvq(zbqry3.fhofrg)
pbe(qngn.fhofrg$cerqvpgrq, qngn.fhofrg$reebe)
