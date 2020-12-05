quest deathmatch_eveniment begin
	state start begin
		function Particip()
			local pozitie = game.get_event_flag("deathmatch_position")
			game.set_event_flag("deathmatch_position", game.get_event_flag("deathmatch_position")+1)
				if pozitie == 0 then
					pc.warp(33324800,33318400)
				elseif pozitie == 1 then
					pc.warp(33324200,33319000)
				elseif pozitie == 2 then
					pc.warp(33324700,33319900)
				elseif pozitie == 3 then
					pc.warp(33325500,33319500)
				elseif pozitie == 4 then
					pc.warp(33325300,33320800)
				elseif pozitie == 5 then
					pc.warp(33326100,33320500)
				elseif pozitie == 6 then
					pc.warp(33325400,33321900)
				elseif pozitie == 7 then
					pc.warp(33326200,33321800)
				elseif pozitie == 8 then
					pc.warp(33325500,33322900)
				elseif pozitie == 9 then
					pc.warp(33326300,33323000)
				elseif pozitie == 10 then
					pc.warp(33325200,33323900)
				elseif pozitie == 11 then
					pc.warp(33325900,33324200)
				elseif pozitie == 12 then
					pc.warp(33324800,33325000)
				elseif pozitie == 13 then
					pc.warp(33325600,33325400)
				elseif pozitie == 14 then
					pc.warp(33324100,33325800)
				elseif pozitie == 15 then
					pc.warp(33324700,33326300)
				elseif pozitie == 16 then
					pc.warp(33323400,33326600)
				elseif pozitie == 17 then
					pc.warp(33323900,33327200)
				elseif pozitie == 18 then
					pc.warp(33322400,33327000)
				elseif pozitie == 19 then
					pc.warp(33322800,33327800)
				elseif pozitie ==  20 then
					pc.warp(33321500,33327400)
				elseif pozitie == 21 then
					pc.warp(33321600,33328200)
				elseif pozitie == 22 then
					pc.warp(33320300,33327400)
				elseif pozitie == 23 then
					pc.warp(33320400,33328300)
				elseif pozitie == 24 then
					pc.warp(33319300,33327400)
				elseif pozitie == 25 then
					pc.warp(33319100,33320200)
				elseif pozitie == 26 then
					pc.warp(33318400,33327000)
				elseif pozitie == 27 then
					pc.warp(33318000,33327700)
				elseif pozitie == 28 then
					pc.warp(33317300,33326600)
				elseif pozitie == 29 then
					pc.warp(33316900,33327200)
				elseif pozitie == 30 then
					pc.warp(33316700,33325800)
				elseif pozitie == 31 then
					pc.warp(33316000,33326300)
				elseif pozitie == 32 then
					pc.warp(33315900,33325000)
				elseif pozitie == 33 then
					pc.warp(33315300,33325400)
				elseif pozitie == 34 then
					pc.warp(33315600,33324000)
				elseif pozitie == 35 then
					pc.warp(33314800,33324200)
				elseif pozitie == 36 then
					pc.warp(33315300,33322900)
				elseif pozitie == 37 then
					pc.warp(33314400,33323000)
				elseif pozitie == 38 then
					pc.warp(33315400,33321900)
				elseif pozitie == 39 then
					pc.warp(33314600,33321800)
				elseif pozitie == 40 then
					pc.warp(33315500,33320800)
				elseif pozitie == 41 then
					pc.warp(33314700,33320500)
				elseif pozitie == 42 then
					pc.warp(33316000,33319900)
				elseif pozitie == 43 then
					pc.warp(33315300,33319500)
				elseif pozitie == 44 then
					pc.warp(33316500,33319000)
				elseif pozitie == 45 then
					pc.warp(33315900,33318400)
				elseif pozitie == 46 then
					pc.warp(33317400,33318300)
				elseif pozitie == 47 then
					pc.warp(33317000,33317700)
				elseif pozitie == 48 then
					pc.warp(33318300,33317700)
				elseif pozitie == 49 then
					pc.warp(33317900,33316900)
				elseif pozitie == 50 then
					pc.warp(33319300,33317500)
				elseif pozitie == 51 then
					pc.warp(33319200,33316700)
				elseif pozitie == 52 then
					pc.warp(33320400,33317200)
				elseif pozitie == 53 then
					pc.warp(33320400,33316400)
				elseif pozitie == 54 then
					pc.warp(33321400,33317500)
				elseif pozitie == 55 then
					pc.warp(33321600,33316700)
				elseif pozitie == 56 then
					pc.warp(33322500,33317700)
				elseif pozitie == 57 then
					pc.warp(33322800,33316900)
				elseif pozitie == 58 then
					pc.warp(33323300,33318300)
				elseif pozitie == 59 then
					pc.warp(33323800,33317700)
				elseif pozitie == 60 then
					pc.warp(33324200,33319000)
				elseif pozitie >= 61 then
					pc.warp(33324200,33319000)
					game.set_event_flag("deathmatch_position",0)
				end
			horse.unride()
			horse.unsummon()
		end

		when 20011.chat."DeathMatch" begin
			if deathmatch.is_status() == 0 then
				say("The event is not in progress")
			else
				say("Event DeathMatch")
				say("You want to participate?")
				local x = select("Yes", "No")
				if x == 1 then
					if deathmatch.is_status() == 2 then
						say("The gates were closed")
						return
					else
						if party.is_party() then
							syschat("You are not allowed with the group.")
							return
						else
							deathmatch_eveniment.Particip()
						end
					end
				elseif x == 2 then
					return
				end
			end
		end
		
		when login begin
			if party.is_party() then
				party.leave_party()
			end
		end
		
		when die with pc.get_map_index() == 359 begin
			timer("goto", 2)
			timer("restart", 4)
		end

		when restart.timer begin
			command("restart_here")
			deathmatch.regen()
		end
		
		when goto.timer begin
			local a = math.random(1,3)
			if a == 1 then
				command("goto_deathmatch 297 202")
			elseif a == 2 then
				command("goto_deathmatch 135 158")
			else
				command("goto_deathmatch 181 318")
			end
		end
		
		when letter with pc.is_gm() begin
			send_letter("*GM* Event DeathMatch")
		end
		
		when button or info with pc.is_gm() begin
			if deathmatch.is_status() == 0 then
				say("Event OFF")
				local y = select("Start event", "Back")
				if y == 1 then
					deathmatch.open_gates()
					big_notice_all("The DeathMatch event has been started, go to Uriel")
				else
					return
				end
			else
				say("Event ON")
				local x = select("Cancel Stun & Start", "Close Event", "Back")
				if x == 1 then
					big_notice_all("The gates were closed.")
					big_notice_all("The event started")
					deathmatch.start()
				elseif x == 2 then
					big_notice_all("The event is over")
					timer("out", 5)
				elseif x == 3 then
					return
				end
			end
		end
		
		when out.timer begin
			deathmatch.close()
		end
	end
end

