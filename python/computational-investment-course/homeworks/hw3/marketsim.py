#!/hfe/ova/rai clguba

vzcbeg pfi
vzcbeg flf
vzcbeg qngrgvzr nf qg
vzcbeg cnaqnf nf cq
vzcbeg ahzcl nf ac
vzcbeg DFGX.dfgxhgvy.dfqngrhgvy nf qh
vzcbeg DFGX.dfgxhgvy.QngnNpprff nf qn

sebz bcrengbe vzcbeg vgrztrggre


qrs trg_beqref(s):
    genqrf = []
    jvgu bcra(s, 'e') nf pfisvyr:
        pfipbagrag = pfi.ernqre(pfisvyr, dhbgrpune=',')
        sbe v va pfipbagrag:
            # [ qngr, pbqr, bcrengvba, inyhr ]
            ebj = [
                qg.qngrgvzr(vag(v[0]), vag(v[1]), vag(v[2])),
                v[3], v[4], sybng(v[5])
            ]
            genqrf.nccraq(ebj)

    genqrf.fbeg(xrl=vgrztrggre(0))

    erghea genqrf


qrs ernq_lnubb_qngn(fgneg_qngr, raq_qngr, yf_flzobyf, yf_xrlf=['pybfr']):
    yqg_gvzrfgnzcf = qh.trgALFRqnlf(fgneg_qngr, raq_qngr, qg.gvzrqrygn(ubhef=16))

    qngnbow = qn.QngnNpprff('Lnubb')

    yqs_qngn = qngnbow.trg_qngn(yqg_gvzrfgnzcf, yf_flzobyf, yf_xrlf)
    erghea qvpg(mvc(yf_xrlf, yqs_qngn))


qrs havdhr_pbqrf(genqrf):
    pbqrf = []
    sbe genqr va genqrf:
        vs abg genqr[1] va pbqrf:
            pbqrf.nccraq(genqr[1])

    erghea pbqrf


qrs zbarl_sbe_genqrf(genqrf, vavgvny_zbarl):
    zbarl = []
    pheerag_zbarl = vavgvny_zbarl

    sbe genqr va genqrf:
        vs genqr[2].ybjre() == "fryy":
            pheerag_zbarl = pheerag_zbarl + (genqr[-1] * -1)
        ryfr:
            pheerag_zbarl = pheerag_zbarl + genqr[-1]

        # [ qngr, zbarl ]
        zbarl.nccraq([genqr[0], pheerag_zbarl])

    erghea zbarl


vs __anzr__ == '__znva__':
    vavgvny_zbarl = sybng(flf.neti[1])
    beqref_svyr   = flf.neti[2]
    inyhrf_svyr   = flf.neti[3]

    genqrf = trg_beqref(beqref_svyr)

    fgneg_qngr = genqrf[0][0]
    raq_qngr   = genqrf[-1][0]

    pbqrf = havdhr_pbqrf(genqrf)
    qngn  = ernq_lnubb_qngn(fgneg_qngr, raq_qngr, pbqrf)

    cevag zbarl_sbe_genqrf(genqrf, vavgvny_zbarl)

    cevag qngn
    cevag fgneg_qngr
    cevag raq_qngr
    cevag genqrf
